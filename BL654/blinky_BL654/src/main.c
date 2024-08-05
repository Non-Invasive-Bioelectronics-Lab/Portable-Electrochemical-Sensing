/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// include libraries 
#include <zephyr/zephyr.h>			// zephyr/zephyr.h for general Zephyr APIs
#include <zephyr/drivers/gpio.h>	// gpio.h for GPIO operations
#include <stdio.h>					// stdio.h for standard I/O operations

// define constants 
// 1000 msec = 1 sec (used to control the LED blinking frequency)
#define SLEEP_TIME_MS   1000

// devicetree node identifier for the "led0" alias.
#define LED0_NODE DT_ALIAS(led0)

// GPIO device specification led based on LED0_NODE (specifies how to interact with the LED using the GPIO)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

//////////////////////////////////////// main fucntion 
void main(void)
{
	// define return variable 
	int ret;

	// check if the led.port is ready or exit 
	if (!device_is_ready(led.port)) 
	{
		return;
	}//end if 

	// the led.port is ready so confugure it as active-high output 
	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) 
	{ 
		return; 
	}//end if 

	// infinite loop 
	while (1) 
	{
		// toggle the LED
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) 
		{ 
			return; 
		}

		// print message to serial terminal 
		printk("LED toggled - %s\n\r", CONFIG_BOARD);

		// sleep 
		k_msleep(SLEEP_TIME_MS);

	}//end while 
	
}//end main 
