 /* LED_CONTROL.c
 *
 *  Created on: Aug 19, 2021
 *      Author: amostafa*/

#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\SPI.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\UART.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\TIMER.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\TIVA.h"
#include<stdio.h>

void SW_ini()
{
    SYSCTL_RCGCGPIO_R |= 0x20;
    GPIO_PORTF_LOCK_R = 0X4C4F434B;
    GPIO_PORTF_CR_R = 0x0F;
    GPIO_PORTF_PUR_R = 0X01;
    GPIO_PORTF_DIR_R |= 0X0E;
    GPIO_PORTF_DEN_R |= 0x1F;
}

void LedInit()
{
     SYSCTL_RCGCGPIO_R |= 0x20;
     GPIO_PORTF_DIR_R = 0x0E;
     GPIO_PORTF_DEN_R = 0X0E;
}

void ASCII()
{
    char s[] ="ON LED";
        int x,i;
        for ( i = 1; i <sizeof(s); i++)
        {
             x=s[i-1];
            printf("%d ",x);
        }
}
