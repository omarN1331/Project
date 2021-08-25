
#include"TIVA.h"
#include<stdint.h>
#include<stdio.h>
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\HAL\LED_CONTROL.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\UART.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\SPI.h"
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\MCAL\TIMER.h"



void apply()
{
     UART_ini_RX();
     SW_ini();
     LedInit();
     INITIALIZE_SPI_MASTER();
while(1)
{
    RX();
    SPI_Transmit(ASCII());
}
}


