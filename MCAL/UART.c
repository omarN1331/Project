
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\TIVA.h"
#include<stdint.h>
#include<stdio.h>
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\TIMER.h"
#include "C:\Users\ayaser\CLionProjects\ProJecT\GP.h"

void UART_ini_RX()
{
    SYSCTL_RCGCUART_R |= 0x02;
    SYSCTL_RCGCGPIO_R |= 0x02;

    UART1_CTL_R &= ~0x01;
    UART1_IBRD_R = 104;
    UART1_FBRD_R = 11;
    UART1_LCRH_R |= 0x70;
    UART1_CTL_R |= 0x301;
    
    PTB_AFSEL |= 0x1;
    PTB_DEN |= 0x1;
    PTB_PCTL |= 0x1;
    PTB_AMSEL = 0x00;
}

void RX()
{
    while((UART1_FR_R & (1<<4)) != 0);
          if((UART1_DR_R & 0xFF) == ASCII())
          {

           GPIO_PORTF_DATA_R = 0x0E;
           Delay();
           GPIO_PORTF_DATA_R &= ~0x0E;
          }
}


