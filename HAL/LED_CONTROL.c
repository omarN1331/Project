 /* LED_CONTROL.c
 *
 *  Created on: Aug 19, 2021
 *      Author: amostafa*/

#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\SPI.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\UART.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\TIMER.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\TIVA.h"
#include<stdio.h>
#include "C:\Users\amostafa\workspace_v10\FINAL PROJECT\mylib.h"

void SW_ini()
{
    GPIO_CLOCK |= 0x20;
    LOCK_F = 0X4C4F434B;
    COMMIT_F  = 0x0F;
    PULL_UP_F = 0X01;
    DIRECTION_F |= 0X0E;
    DIGITAL_E_F |= 0x1F;

void LedInit()
{
     GPIO_CLOCK |= 0x20;
     DIRECTION_F = 0x0E;
     DIGITAL_E_F = 0X0E;
}

int ASCII()
{
    char s[] ="ON LED";
        int x,i;
        for ( i = 1; i <sizeof(s); i++)
        {
             x=s[i-1];
        }
        return x;
}

