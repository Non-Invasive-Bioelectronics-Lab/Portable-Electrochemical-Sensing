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

#include <zephyr/settings/settings.h>

// define device tree node for the "led0" alias
#define LED0_NODE DT_ALIAS(led0)

// create struct of the led properties 
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

#define ADCPGA_GAIN_SEL ADCPGA_1P5      // constant value = 1 (AD5941 PGA for ADC is 1.5)

// PGA Calibration function  
static void AD5940_PGA_Calibration(void)
{
  AD5940Err err;
  ADCPGACal_Type pgacal;
  pgacal.AdcClkFreq = 16e6;
  pgacal.ADCSinc2Osr = ADCSINC2OSR_178;
  pgacal.ADCSinc3Osr = ADCSINC3OSR_4;
  pgacal.SysClkFreq = 16e6;
  pgacal.TimeOut10us = 1000;
  pgacal.VRef1p11 = 1.11f;
  pgacal.VRef1p82 = 1.82f;
  pgacal.PGACalType = PGACALTYPE_OFFSETGAIN;
  pgacal.ADCPga = ADCPGA_GAIN_SEL;
  err = AD5940_ADCPGACal(&pgacal);
  if(err != AD5940ERR_OK)
  {
    printf("AD5940 PGA calibration failed.\n\r");
  }
  else 
  {
    printf("AD5940 PGA calibration Success.\n\r");
  }
}//end function 

// 1000 msec = 1 sec (used to control the LED blinking frequency)
#define SLEEP_TIME_MS   1000

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
    adc_filter.ADCAvgNum = ADCAVGNUM_2;         /* Don't care about it. Average function is only used for DFT */
    adc_filter.ADCRate = ADCRATE_800KHZ;        /* If ADC clock is 32MHz, then set it to ADCRATE_1P6MHZ. Default is 16MHz, use ADCRATE_800KHZ. */
    adc_filter.BpNotch = bTRUE;                 /* SINC2+Notch is one block, when bypass notch filter, we can get fresh data from SINC2 filter. */
    adc_filter.BpSinc3 = bFALSE;                /* We use SINC3 filter. */   
    adc_filter.Sinc2NotchEnable = bTRUE;        /* Enable the SINC2+Notch block. You can also use function AD5940_AFECtrlS */ 
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

}//end main