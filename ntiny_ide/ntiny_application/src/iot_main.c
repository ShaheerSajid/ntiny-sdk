#include "dht.h"
#include <stdlib.h>
#include <stdint.h>
#include "init.h"
#include "uart.h"
#include "timer.h"
#include "gpio.h"
#include "ee_printf.h"
#include "pwm.h"

/// main fucntion
int main(void)
{
	//UART
	int_disable();
	uart_init(9600);

	//variable declarations for temperature
	int cnt = 0;
	float temp[1];
	float humid[1];

	//Initialise LIGHT and Turn it OFF
	gpio_mode(1,1);
	int state = 0;
	state = 1;
	gpio_write_pin(1,state);

	//Initialise FAN and lower the Speed
	pwm_init();
	set_compare1(0);
	pwm1_start();

	while(1){

		if (dht_read(temp,humid))
		{
			//TERMINAL
			//Uncomment to use term=minal interface
			//ee_printf("Temp %d: %.1f;",cnt,*temp);
			//ee_printf("Hum %d: %.1f;",cnt,*humid);

			//Receiver Interface
			//Uncomment to use the receiver interface
			ee_printf("%.1f,",cnt,*temp);
			ee_printf("%.1f;",cnt,*humid);
			cnt++;
		}

		if(uart_haschar())
			{
			char y = uart_getchar();
			int val = y - 48;
			if(y == 'N')
				{
				//Turn ON
				state = 0;
				gpio_write_pin(1,state);
				set_compare1(val * 300);
				}
		else if (y == 'F')
			{
				//Turn OFF
				state = 1;
				gpio_write_pin(1,state);
				set_compare1(0);
			}

		}



	delay_ms(1000);

}

return 0;
}
