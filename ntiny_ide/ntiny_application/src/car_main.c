/*
 * main.c
 *
 *  Created on: 28 Dec 2021
 *      Author: shaheer
 */
#include <stdlib.h>
#include <stdint.h>
#include "init.h"
#include "uart.h"
#include "ee_printf.h"
#include "timer.h"
#include "gpio.h"
#include "pwm.h"

/*
void ISR_EXT (void)
{
	volatile uint32_t	*m_uart	= 	(volatile uint32_t *)UART_BASE_ADDR;
    int x = 0;
	char *data = "External Interrupt\n";
	while (data[x] != 0)
		{
			//*sim_uart = data[x];
			 m_uart[U_TX/4] = data[x];
			while (m_uart[U_STATUS/4] & (1 << U_STATUS_TXFULL_SHIFT)){

			}
			x++;
		}
	__asm("jalr x0, x1");
}

void ISR_TIMER (void)
{
	volatile uint32_t	*m_uart	= 	(volatile uint32_t *)UART_BASE_ADDR;
    int x = 0;
	char *data = "Timer Interrupt\n";
	while (data[x] != 0)
		{
			//*sim_uart = data[x];
			 m_uart[U_TX/4] = data[x];
			while (m_uart[U_STATUS/4] & (1 << U_STATUS_TXFULL_SHIFT)){

			}
			x++;
		}
	__asm("jalr x0, x1");


}
*/
void stop()
{
	gpio_write_pin(0,0);
	gpio_write_pin(1,0);
	gpio_write_pin(2,0);
	gpio_write_pin(3,0);

}

void forward()
{
	gpio_write_pin(0,1);
	gpio_write_pin(1,0);
	gpio_write_pin(2,0);
	gpio_write_pin(3,1);

}
void backward()
{
	gpio_write_pin(0,0);
	gpio_write_pin(1,1);
	gpio_write_pin(2,1);
	gpio_write_pin(3,0);

}
void left()
{
	gpio_write_pin(0,0);
	gpio_write_pin(1,1);
	gpio_write_pin(2,0);
	gpio_write_pin(3,1);

}
void right()
{
	gpio_write_pin(0,1);
	gpio_write_pin(1,0);
	gpio_write_pin(2,1);
	gpio_write_pin(3,0);

}
int main(void)
{

	int_disable();
	uart_init(9600);

	gpio_mode(0,1);
	gpio_mode(1,1);
	gpio_mode(2,1);
	gpio_mode(3,1);

	gpio_mode(4,0);
	gpio_mode(5,0);
	gpio_mode(6,0);

	pwm_init();
	set_compare1(2000);
	pwm1_start();

	while(1){

		if(uart_haschar())
		{
			char y = uart_getchar();
			if(y == 'F')
			{
				forward();
				delay_ms(100);
			}
			else if(y == 'R')
			{
				right();
				delay_ms(100);
			}
			else if(y == 'L')
			{
				left();
				delay_ms(100);
			}
			else if(y == 'B')
			{
				backward();
				delay_ms(100);
			}
			else if(y=='W')
			{
				set_compare1(1500);
			}
			else if(y=='w')
			{
				set_compare1(500);
			}
			else if(y== 'S')
			{
				stop();
			}
		}
		/*else if((!gpio_read_pin(4) && gpio_read_pin(5) && !gpio_read_pin(6)) || (gpio_read_pin(4) && gpio_read_pin(5) && gpio_read_pin(6)))
			backward();
		else if((!gpio_read_pin(4) && gpio_read_pin(6)))
			left();
		else if((gpio_read_pin(4) && !gpio_read_pin(6)))
			right();*/
		else
			stop();
	}
	return 1;

}
