#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\APPLICATION\application.h"
#include<stdint.h>
#include"C:\Users\amostafa\workspace_v10\FINAL PROJECT\TIVA.h"

/*void UART_ini_TX()
{
    SYSCTL_RCGCUART_R |= 0x02;
         SYSCTL_RCGCGPIO_R |= 0x02;

         UART1_CTL_R &= ~0x01;
         UART1_IBRD_R = 104;
         UART1_FBRD_R = 11;
         UART1_LCRH_R |= 0x07;
         UART1_CTL_R |= 0x301;

         GPIO_PORTB_AFSEL_R |= 0x20;
         GPIO_PORTB_DEN_R |= 0x20;
         GPIO_PORTB_PCTL_R |= 0x10;
         GPIO_PORTB_AMSEL_R = 0x00;
}
*/
/*
void RX()
{
    while((UART1_FR_R & (1<<4)) != 0);
          if((UART1_DR_R & 0xFF) == 0x01)
              GPIO_PORTF_DATA_R = 0x0E;
          else if ((UART1_DR_R & 0xFF) == 0x00)
              GPIO_PORTF_DATA_R &= ~0x0E;
}

*/

int main(void)
{
   apply();

}

