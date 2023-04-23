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

	gpio_mode(7,1);


	pwm_init();
	set_compare1(1500);
	pwm1_start();

	while(1){
		if(uart_haschar())
		{
			char y = uart_getchar();
			if(y == 'F')
			{
				backward();
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
				forward();
				delay_ms(100);
			}
			else if(y=='W')
			{
				set_compare1(1000);
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
		else
		{
			delay_ms(50);
			gpio_write_pin(7,1);
			delay_ms(50);
			gpio_write_pin(7,0);
		}
	}
	return 1;

}
