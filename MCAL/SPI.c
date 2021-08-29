 /* SPI.c
 *
 *  Created on: Aug 19, 2021
 *      Author: amostafa*/



#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\TIVA.h"
#include "C:\Users\onasser\Desktop\PORTAheader.h"
#include "C:\Users\amostafa\workspace_v10\FINAL PROJECT\mylib.h"

void INITIALIZE_SPI_MASTER()
{
    SYSCTL_RCGCSSI_R |= 0x1; // Enable and provide a clock to SPI0
                    GPIO_CLOCK |= 0x21; // Enable and provide a clock to GPIO PortA & portf
                    AFSEL_A |= 0x3C; // Enable alternate functions on PA2, PA3, PA4, PA5
                                   PCTL_A |= 0x222200; // Assign SPI signals to PA2, PA3, PA4, PA5
                                   DEN_A |= 0x3C; // Enable digital functions for PA2, PA3, PA4, PA5
                                   DIR_A |= 0x8; // Set PA3 as output
                                   DATA_A |= 0x8;
                                   LOCK_F   = 0X4C4F434B;
                                   COMMIT_F =0X01;
                                   ANALOG_S_F = 0;
                                   PORT_CONTROL_F &= 0xFFFFFFF0;
                                   PULL_UP_F=0x10;
                                   DIGITAL_E_F |= 0X1E;// Make slave select line high when idle
                                   DIRECTION_F |= 0X0E;
                                   SSI0_CR1_R |= 0x0; // Disable SPI and configure it as a master
                                   SSI0_CC_R |= 0x0; // Select the SPI Baud Clock Source as system clock
                                   SSI0_CPSR_R |= 0x10; // Set the clock frequency to 1 MHz
                                   SSI0_CR0_R = 0x7; // Freescale SPI mode, 1 Mbps bit rate, 8 data bits
                                   SSI0_CR1_R |= 0x2; // Enable SPI
}

void SPI_Transmit(char c)       //for master
{
    DATA_A &= ~0x8; // Select the slave by making active-low slave select line low
    while((SSI0_SR_R & 0x2) == 0x00); // wait until transmit FIFO is not full
    SSI0_DR_R = c; // send the data
    while((SSI0_SR_R & 0x10) == 0x10); //  wait until busy bit becomes 0
    DATA_A |= 0x8; // Deselect the slave
}
