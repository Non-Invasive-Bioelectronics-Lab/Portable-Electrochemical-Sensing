#include <stdio.h>
#include <drivers/gpio.h>
#include <drivers/spi.h>
#include "ad5940_lib/ad5940.h"

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/zephyr.h>
#include "Amperometric.h"
#include <zephyr/settings/settings.h>

#define APPBUFF_SIZE 100
uint32_t AppBuff[APPBUFF_SIZE];
float LFOSCFreq;

// define device tree node for the "led0" alias
#define LED0_NODE DT_ALIAS(led0)

// create struct of the led properties
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

#define ADCPGA_GAIN_SEL ADCPGA_1P5      // constant value = 1 (AD5941 PGA for ADC is 1.5)

///////////////////////////////////////////////// setup AD5940 basic blocks like clock
static int32_t AD5940PlatformCfg(void)
{
  CLKCfg_Type clk_cfg;
  FIFOCfg_Type fifo_cfg;
  SEQCfg_Type seq_cfg;
  AGPIOCfg_Type gpio_cfg;
  LFOSCMeasure_Type LfoscMeasure;
  
  ////////////////////////////////////// Use hardware reset
  AD5940_HWReset();
  
  ////////////////////////////////////// Platform configuration
  AD5940_Initialize();
  
  ////////////////////////////////////// Step1. Configure clock
  clk_cfg.HFOSCEn = bTRUE;
  clk_cfg.HFXTALEn = bFALSE;
  clk_cfg.LFOSCEn = bTRUE;
  clk_cfg.HfOSC32MHzMode = bFALSE;
  clk_cfg.SysClkSrc = SYSCLKSRC_HFOSC;
  clk_cfg.SysClkDiv = SYSCLKDIV_1;
  clk_cfg.ADCCLkSrc = ADCCLKSRC_HFOSC;
  clk_cfg.ADCClkDiv = ADCCLKDIV_1;
  
  AD5940_CLKCfg(&clk_cfg);
  /////////////////////////////////////// Step2. Configure FIFO and Sequencer
  fifo_cfg.FIFOEn = bFALSE;
  fifo_cfg.FIFOMode = FIFOMODE_FIFO;
  fifo_cfg.FIFOSize = FIFOSIZE_4KB;       // 4kB for FIFO, The rest 2kB for sequencer
  fifo_cfg.FIFOSrc = FIFOSRC_DFT;
  fifo_cfg.FIFOThresh = 4;
  AD5940_FIFOCfg(&fifo_cfg);              // Disable to reset FIFO
  fifo_cfg.FIFOEn = bTRUE;
  AD5940_FIFOCfg(&fifo_cfg);
  
  ////////////////////////////////////////// Configure sequencer and stop it
  seq_cfg.SeqMemSize = SEQMEMSIZE_2KB;
  seq_cfg.SeqBreakEn = bFALSE;
  seq_cfg.SeqIgnoreEn = bFALSE;
  seq_cfg.SeqCntCRCClr = bTRUE;
  seq_cfg.SeqEnable = bFALSE;
  seq_cfg.SeqWrTimer = 0;
  AD5940_SEQCfg(&seq_cfg);
  
  /////////////////////////////////////////// Step3. Interrupt controller
  AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);           /* Enable all interrupt in Interrupt Controller 1, so we can check INTC flags */
  AD5940_INTCCfg(AFEINTC_0, AFEINTSRC_DATAFIFOTHRESH, bTRUE);   /* Interrupt Controller 0 will control GP0 to generate interrupt to MCU */
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);
  
  /////////////////////////////////////////// Step4: Reconfigure GPIO
  gpio_cfg.FuncSet = GP6_SYNC|GP5_SYNC|GP4_SYNC|GP2_SYNC|GP1_SLEEP|GP0_INT;
  gpio_cfg.InputEnSet = 0;
  gpio_cfg.OutputEnSet = AGPIO_Pin0|AGPIO_Pin1|AGPIO_Pin4|AGPIO_Pin5|AGPIO_Pin6|AGPIO_Pin2;
  gpio_cfg.OutVal = 0;
  gpio_cfg.PullEnSet = 0;
  AD5940_AGPIOCfg(&gpio_cfg);
  AD5940_SleepKeyCtrlS(SLPKEY_UNLOCK);          // Allow AFE to enter sleep mode
  /* Measure LFOSC frequency */
  LfoscMeasure.CalDuration = 1000.0;            // 1000 ms used for calibration
  LfoscMeasure.CalSeqAddr = 0;
  LfoscMeasure.SystemClkFreq = 16000000.0f;     // 16 MHz in this firmware
  AD5940_LFOSCMeasure(&LfoscMeasure, &LFOSCFreq);
  return 0;
}//end

void AD5940AMPStructInit(void)
{
  AppAMPCfg_Type *pAMPCfg;
  AppAMPGetCfg(&pAMPCfg);
  pAMPCfg->WuptClkFreq = LFOSCFreq;
  
  // Configure general parameters
  pAMPCfg->SeqStartAddr = 0;
  pAMPCfg->MaxSeqLen = 1000;                // @todo add checker in function
  pAMPCfg->RcalVal = 10000.0;
  pAMPCfg->NumOfData = -1;                  // Never stop until you stop it manually by AppAMPCtrl() function

  // Configure measurement parameters
  pAMPCfg->AmpODR = 1;                      // Time between samples in seconds
  pAMPCfg->FifoThresh = 1;                  // Number of measurements before alerting host MCU
  pAMPCfg->SensorBias = 200;                // Sensor bias voltage between reference and sense electrodes
  pAMPCfg->LptiaRtiaSel = LPTIARTIA_1K;
  pAMPCfg->LpTiaRl = LPTIARLOAD_10R;
  pAMPCfg->Vzero = 1100;                    // Vzero voltage. Voltage on Sense electrode. Unit is mV
  pAMPCfg->ADCRefVolt = 1.82;               // voltage on Vref_1V8 pin
}//end function

// 1000 msec = 1 sec (used to control the LED blinking frequency)
#define SLEEP_TIME_MS   1000

///////////////////////////////////////////////////////// display the result in UART
int32_t AMPShowResult(float *pData, uint32_t DataCount)
{
    float x = pData[0];

    // float bias_current = 39.5;
    // x = x - bias_current;

    // process the measured differential voltage
    int x_int = (int) x;		// integer part
    int x_frac = (int) ((x - x_int) * 10000);
	// print to serial terminal
	// printf ("Int = %d, Decimal = %d \n\r", diff_volt_int, diff_volt_dec_int);
    printf("Current: %d.%04d uA\n\r", x_int, x_frac);

    return 0;
}//end

////////////////////////////////////////////////// MAIN //////////////////////////////////////
void main(void)
{
    // define return variable
	int ret;

    // check if led device is ready
	if (!device_is_ready(led.port)) { return; }

    // set the led to active-high output
	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) { return; }

    // toggle the led 5 times before starting the program
	int led_counter = 0;
    while (led_counter < 5)
	{
		gpio_pin_toggle_dt(&led);
		k_msleep(SLEEP_TIME_MS);
		led_counter = led_counter + 1;
	}//end while

      // setup the MCU resources for connecting with AD5940
    AD5940_MCUResourceInit(0);
    AD5940_Delay10us(50000);        // delay 500 m

    printf("MCU initialized \n\r");

    // call platform configuration
    AD5940PlatformCfg();
    AD5940_Delay10us(50000);    // delay 500 m

    printf("Platform configured \n\r");

    AD5940AMPStructInit();      // Configure your parameters in this function
    AD5940_Delay10us(50000);    // delay 500 m

    printf("Parameters configured \n\r");

    // setup AMP application (provide a buffer, which is used to store sequencer commands)
    AppAMPInit(AppBuff, APPBUFF_SIZE);
    AD5940_Delay10us(50000);    // delay 500 m

    // control AMP measurement to start (s)
    AppAMPCtrl(AMPCTRL_START, 0);
    AD5940_Delay10us(50000);    // delay 500 m

    printf("Application started  \n\r");

    /////////////////////////////////////////////// Main Loop
    while (1)
    {
        // printf("Waiting for interrupt \n\r");
      
        if(AD5940_GetMCUIntFlag())
        {
            printf("Interrupt detected \n\r");

            AD5940_ClrMCUIntFlag(); /* Clear this flag */

            /// display data
            uint32_t temp = APPBUFF_SIZE;
            AppAMPISR(AppBuff, &temp);
            AMPShowResult((float*)AppBuff, temp);
        }
        else
        {
            AD5940_Delay10us(10);  // delay 1 sec
        }

        AD5940_Delay10us(10);  // delay 1 sec

    }//end while

    /*

    // setup the MCU resources for connecting to AD5940 (initializae the MCU - defined in BL654Port.c)
    AD5940_MCUResourceInit(0);

	// ADC measurement of AD5940/41
    ADCBaseCfg_Type adc_base;
    ADCFilterCfg_Type adc_filter;

    // Use hardware reset (RESET pin is set and reset)
    AD5940_HWReset();

    // initialize the AD5941 device by writing to its registers
    AD5940_Initialize();

	// PGA calibration function
    AD5940_PGA_Calibration();

    // configure AFE power mode and bandwidth
    AD5940_AFEPwrBW(AFEPWR_LP, AFEBW_250KHZ);

    // initialize the ADC basic function (measurement is done based on DAC 1.82 V reference)
    AD5940_AFECtrlS(AFECTRL_DACREFPWR|AFECTRL_HSDACPWR, bTRUE);

	// set the differential inputs for the ADC
	adc_base.ADCMuxP = ADCMUXP_VREF1P8DAC; 		    // 1.8 V
    // adc_base.ADCMuxP = ADCMUXP_VREF2P5;          // positive input set to 1.25 V
    adc_base.ADCMuxN = ADCMUXN_VSET1P1;    			// negative input set to 1.1 V
	// select the programmable gain defined
    adc_base.ADCPga = ADCPGA_GAIN_SEL;
    AD5940_ADCBaseCfgS(&adc_base);

    // Initialize the ADC filters ADCRawData-->SINC3-->SINC2+NOTCH
    adc_filter.ADCSinc3Osr = ADCSINC3OSR_4;
    adc_filter.ADCSinc2Osr = ADCSINC2OSR_1333;
    adc_filter.ADCAvgNum = ADCAVGNUM_2;         // Don't care about it. Average function is only used for DFT
    adc_filter.ADCRate = ADCRATE_800KHZ;        // If ADC clock is 32MHz, then set it to ADCRATE_1P6MHZ. Default is 16MHz, use ADCRATE_800KHZ.
    adc_filter.BpNotch = bTRUE;                 // SINC2+Notch is one block, when bypass notch filter, we can get fresh data from SINC2 filter.
    adc_filter.BpSinc3 = bFALSE;                // We use SINC3 filter.
    adc_filter.Sinc2NotchEnable = bTRUE;        // Enable the SINC2+Notch block. You can also use function AD5940_AFECtrlS
    AD5940_ADCFilterCfgS(&adc_filter);

    //AD5940_ADCMuxCfgS(ADCMUXP_AIN2, ADCMUXN_VSET1P1);   // Optionally, you can change ADC MUX with this function

    // Enable all interrupt at Interrupt Controller 1. So we can check the interrupt flag
    AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);

    //AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);
    //AD5940_AFECtrlS(AFECTRL_ADCCNV, bTRUE);
    AD5940_ADCPowerCtrlS(bTRUE);
    AD5940_ADCConvtCtrlS(bTRUE);

	// keep reading ADC value and send to the mobile app via BLE protocol
    while(1)
    {
        uint32_t rd;

        if(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_SINC2RDY))
        {
            static uint32_t count;
            AD5940_INTCClrFlag(AFEINTSRC_SINC2RDY);
            rd = AD5940_ReadAfeResult(AFERESULT_SINC2);
            count ++;

            // ADC Sample rate is 800kSPS. SINC3 OSR is 4, SINC2 OSR is 1333.
            // So the final output data rate is 800 kSPS/4/1333 = 150.0375 Hz
            if(count == 150) // Print the data @0.5Hz
            {
                count = 0;
                float diff_volt = AD5940_ADCCode2Volt(rd, ADCPGA_GAIN_SEL, 1.82);

				// process the measured differential voltage
                int diff_volt_int = (int) diff_volt;		// integer part
                int diff_volt_frac = (int) ((diff_volt - diff_volt_int) * 10000);
				// print to serial terminal
				// printf ("Int = %d, Decimal = %d \n\r", diff_volt_int, diff_volt_dec_int);
                printf("Differential Voltage: %d.%04d V\n\r", diff_volt_int, diff_volt_frac);
            }//end if

        }//end if

    }//end while

    */

}//end main
