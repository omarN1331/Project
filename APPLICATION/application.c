
#include"TIVA.h"
#include<stdint.h>
#include<stdio.h>
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\HAL\LED_CONTROL.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\UART.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\SPI.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\TIMER.h"



void apply()
{

     char RED='W';
     UART_ini_RX();
   //  UART_ini_TX();
     SW_ini();
     LedInit();
     INITIALIZE_SPI_MASTER();

while(1)
{
    RX();
   if(!(GPIO_PORTF_DATA_R & 0x10))
    {
       SPI_Transmit(RED);
    }

}


}


