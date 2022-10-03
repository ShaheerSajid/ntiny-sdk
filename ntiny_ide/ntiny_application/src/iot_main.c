#include "dht.h"
#include <stdlib.h>
#include <stdint.h>
#include "init.h"
#include "uart.h"
#include "ee_printf.h"
#include "timer.h"
#include "gpio.h"
#include "pwm.h"


/// main fucntion
int main(void)
{
	int_disable();
	uart_init(9600);
	float temp[1];		//variable declarations
	float humid[1];


	pwm_init();
	set_compare1(20);
	pwm1_start();
	gpio_mode(1,1);
	int cnt = 0;
	int state = 0;

	while(1){

				if(dht_read(temp,humid))
				{
					//checks if dht_read is valid
					ee_printf("*TX%dY%.1f",cnt,*temp);		//sends data through the wireless channel
					ee_printf("*HX%dY%.1f",cnt,*humid);		//sends data through the wireless channel

				}
				if(uart_haschar())
				{
					char y = uart_getchar();
					int val = y - 48;
					set_compare1(val * 300);
					if(y == 'M')
					{
						gpio_write_pin(1,state);
						state = !state;
					}
				}
				delay_ms(1000);
				cnt++;
				if(cnt > 60)
				{
					uart_puts("*TC");
					uart_puts("*HC");
					cnt = 0;
				}
	}

	return 0;
}
