 /* SPI.c
 *
 *  Created on: Aug 19, 2021
 *      Author: amostafa*/



#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\TIVA.h"

void INITIALIZE_SPI_MASTER()
{
    SYSCTL_RCGCSSI_R |= 0x1; // Enable and provide a clock to SPI0
                    SYSCTL_RCGCGPIO_R |= 0x21; // Enable and provide a clock to GPIO PortA & portf
                    GPIO_PORTA_AFSEL_R |= 0x3C; // Enable alternate functions on PA2, PA3, PA4, PA5
                                   GPIO_PORTA_PCTL_R |= 0x222200; // Assign SPI signals to PA2, PA3, PA4, PA5
                                   GPIO_PORTA_DEN_R |= 0x3C; // Enable digital functions for PA2, PA3, PA4, PA5
                                   GPIO_PORTA_DIR_R |= 0x8; // Set PA3 as output
                                   GPIO_PORTA_DATA_R |= 0x8;
                                   GPIO_PORTF_LOCK_R = 0X4C4F434B;
                                   GPIO_PORTF_CR_R=0X01;
                                   GPIO_PORTF_AMSEL_R = 0;
                                   GPIO_PORTF_PCTL_R &= 0xFFFFFFF0;
                                   GPIO_PORTF_PUR_R=0x10;
                                   GPIO_PORTF_DEN_R |= 0X1E;// Make slave select line high when idle
                                   GPIO_PORTF_DIR_R |= 0X0E;
                                   SSI0_CR1_R |= 0x0; // Disable SPI and configure it as a master
                                   SSI0_CC_R |= 0x0; // Select the SPI Baud Clock Source as system clock
                                   SSI0_CPSR_R |= 0x10; // Set the clock frequency to 1 MHz
                                   SSI0_CR0_R = 0x7; // Freescale SPI mode, 1 Mbps bit rate, 8 data bits
                                   SSI0_CR1_R |= 0x2; // Enable SPI
}

void SPI_Transmit(char c)       //for master
{
    GPIO_PORTA_DATA_R &= ~0x8; // Select the slave by making active-low slave select line low
    while((SSI0_SR_R & 0x2) == 0x00); // wait until transmit FIFO is not full
    SSI0_DR_R = c; // send the data
    while((SSI0_SR_R & 0x10) == 0x10); //  wait until busy bit becomes 0
    GPIO_PORTA_DATA_R |= 0x8; // Deselect the slave
}
