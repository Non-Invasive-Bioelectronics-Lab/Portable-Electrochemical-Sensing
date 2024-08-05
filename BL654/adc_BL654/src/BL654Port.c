#include <stdio.h>
#include <zephyr/zephyr.h>
#include <drivers/gpio.h>
#include <drivers/spi.h>

////////////////// This code is required to allow the BL654 module to use the AD5940 library  

/* The devicetree node identifier for using the GPIO pins */
#define GPIO_NODE DT_NODELABEL(gpio0)
#define SPI_NODE DT_NODELABEL(spi1)

#define RESET_PIN 30
#define CS_PIN 31

// define the GPIO device 
const struct device *const gpio_dev = DEVICE_DT_GET(GPIO_NODE);
// define the SPI device 
const struct device *const spi_dev = DEVICE_DT_GET(SPI_NODE);

// define the return value 
int ret = 0;

// interrupt indicator flag (interrupt occurred if ucInterrupted == 1)
volatile static uint8_t ucInterrupted = 0;

/////////////////////////////////////////// delay function: resulting delay (uS) = input (uint32_t) x 10 us)
void AD5940_Delay10us(uint32_t time)
{
    if (time == 0) time = 1;
    uint32_t time_total_us = time * 10 ; 
    k_usleep(time_total_us);
}//end

/////////////////////////////////////////// return interrupt indicator flag
uint32_t AD5940_GetMCUIntFlag(void)
{
    return ucInterrupted;
}//end

/////////////////////////////////////////// clear CS pin of AD5940
void AD5940_CsClr(void)
{
    // clear CS_PIN
    gpio_pin_set(gpio_dev, CS_PIN, 0);
}//end

/////////////////////////////////////////// set CS pin of AD5940
void AD5940_CsSet(void)
{
    // set CS_PIN
    gpio_pin_set(gpio_dev, CS_PIN, 1);
}//end

/////////////////////////////////////////// clear RESET pin of AD5940
void AD5940_RstClr(void)
{
    // clear RESET_PIN
    gpio_pin_set(gpio_dev, RESET_PIN, 0);
}//end

/////////////////////////////////////////// set RESET pin of AD5940
void AD5940_RstSet(void)
{
     // set RESET_PIN
    gpio_pin_set(gpio_dev, RESET_PIN, 1);
}//end

/////////////////////////////////////////////////////////////// spi configuration 
static const struct spi_config spi_cfg = 
{ 
    // SPI_OP_MODE_MASTER 
    // SPI_WORD_SET(_word_size_) = 8 bits 
    // Clock Polarity: set low (default): SPI_MODE_CPOL
    // Clock Phase: set high
    // First bit: MSB
	.operation = SPI_WORD_SET(8) | SPI_TRANSFER_MSB | SPI_OP_MODE_MASTER,
	.frequency = 8000000,
};

/////////////////////////////////////////// setup function: MCU peripherals (GPIO pins, SPI, interrupt)
uint32_t AD5940_MCUResourceInit(void *pCfg)
{
    // set the AD5941 CS pin and the RESET pin to outputs

    // SIO_31 connected to CS pin   
    ret = gpio_pin_configure(gpio_dev, CS_PIN, GPIO_OUTPUT);
    if (ret < 0) { 	printf("error A ... \n\r") ; }

    // SIO_30 connected to RESET pin   
    ret = gpio_pin_configure(gpio_dev, RESET_PIN, GPIO_OUTPUT);
    if (ret < 0) { 	printf("error B ... \n\r") ; }

    if(!device_is_ready(spi_dev)) 
    {
		printf("SPI master device is not ready!\n");
	}

    // activate the SPI functionality on the designated pins

    /* 
     * SPI configuration based on AD5940 requirements:
     *  data size = 8 bits
     *  CLK polarity = LOW (inactive is low CLK)
     *  CLK phase = HIGH (data is captured on the first UCLK edge and changed on the following edge)
     *  master mode = enabled
     *  SYNC mode = enabled
     *  first bit = Most Significant Bit
     *  SPI clock = SMCLK 8 MHz (should be less than 16 MHz)
     *  pre-scalar setting (0x20 = 32, F(BitClock) = F(BRCLK) / 32)
     */
    
    // enable external interrupt on pin

    return 0;
}//end

//////////////////////////////////////// Read and Write function 
void AD5940_ReadWriteNBytes(unsigned char *pSendBuffer, unsigned char *pRecvBuff, unsigned long length)
{
	const struct spi_buf tx_buf = 
    {
		.buf = pSendBuffer,
		.len = length
	};
	const struct spi_buf_set tx = 
    {
		.buffers = &tx_buf,
		.count = 1
	};

	struct spi_buf rx_buf = 
    {
		.buf = pRecvBuff,
		.len = length,
	};
	const struct spi_buf_set rx = 
    {
		.buffers = &rx_buf,
		.count = 1
	};

	// Start transaction
	int error = spi_transceive(spi_dev, &spi_cfg, &tx, &rx);
	if(error != 0)
    {
		printf("SPI transceive error \n");
	}

 }//end 
