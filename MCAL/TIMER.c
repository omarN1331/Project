 /* TIMER.c
 *
 *  Created on: Aug 19, 2021
 *      Author: amostafa*/


#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\TIVA.h"

#define DELAY_FOR_ONE_SECOND                          (160000000 * 1) - 1


void delay(int n)
{
                           int i;
                           NVIC_ST_CTRL_R |=0 ;    //able & count to zero        /* disable SysTick during setup */
                           NVIC_ST_RELOAD_R = DELAY_FOR_ONE_SECOND;    /* Reload Value goes here */
                           NVIC_ST_CTRL_R |= 0x5;          /* enable SysTick with core clock */
                           for(i=0;i<n;i++)          /* n is a number of loops that decates the seconds */
                           {
                               while( (NVIC_ST_CTRL_R & (1<<16) ) == 0);   /* Monitoring bit 16 to be set */

                           }
                                                          ;
                           NVIC_ST_CTRL_R = 0;             /* Disabling SysTick Timer */
}

