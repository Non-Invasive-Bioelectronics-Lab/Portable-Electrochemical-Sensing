# MSP430-FR-5739

This folder explains how to connect the AD5941 Electrochemical Front End (EFE) provided by Analog Devices (AD) to the MSP430FR5739 microcontroller provided by Texas Instruments (TI).      

A development boards of the two modules are used in this demonstration.

The first code project (adc) is used to perform Open Circuit Potential (OCP) measurements through differential voltage measurements via the embedded 16-bit ADC and the input multiplexer.      

The second code project (amperometric) covers the amperometric measurement performed using the low bandwidth AFE loop (dual VDAC source module and the trans-impedance amplifier circuit).      

MSP430 development board:             

![MSP430 Board](images/msp430.png)   

AD5941 evaluation board:             

![AD5941 Board](images/ad5941.png)   

The connections between the two boards are shown below:        

![AD5941 Board](images/connections_1.png)   
