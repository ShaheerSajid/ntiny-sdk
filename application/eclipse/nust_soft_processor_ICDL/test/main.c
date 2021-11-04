/*
 * main.c
 *
 *  Created on: 3 Nov 2021
 *      Author: shaheer
 */

#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "timer.h"

#define  SCALE  10000
#define  ARRINIT  2000
int main()
{
	uart_init(115200);
	while(1)
	{
		timer_set_prescaler(1); // set value by which you want to divide the clock frequency
		timer_set_compare(-1);
		timer_set_count(0);
		timer_start();
		printf("Ntiny-EV is Alive: ");
		/*int  digits = 100*14/4;
		int  carry = 0;
		int  arr[digits + 1];
		for (int  i = 0; i <= digits; ++i)
			arr[i] = ARRINIT;
		for (int  i = digits; i > 0; i-= 14) {
			int  sum = 0;
			for (int  j = i; j > 0; --j) {
				sum = sum * j + SCALE * arr[j];
				arr[j] = sum % (j * 2 - 1);
				sum /= j * 2 - 1;
		}
			printf("%04d",carry+sum/SCALE);
			carry = sum % SCALE;
		}*/
		timer_stop();
		//printf("\n");
		int  cnt = timer_read_count_value();
		printf("Cycles: %d\n",cnt);
	}
}


