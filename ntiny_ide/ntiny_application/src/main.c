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
#include "timer.h"
#include "csr.h"
#include "gpio.h"
//#include "ee_printf.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

//xQueueHandle SimpleQueue;

void task1 (void *pvParameters) {

	//int i = 222;
	static int state = 0;
	while(1) {

		gpio_write_pin(0,state);
		state = !state;
		//xQueueSend(SimpleQueue, &i, portMAX_DELAY);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}


	vTaskDelete(NULL);

}

void task2 (void *pvParameters) {

	//int received=0;
	static int state1 = 0;
	while(1) {

		gpio_write_pin(1,state1);
		state1 = !state1;

		vTaskDelay(pdMS_TO_TICKS(100));


		/*if (xQueueReceive(SimpleQueue, &received, portMAX_DELAY) == pdTRUE)
		{
			if (received == 222)
				uart_puts("222\n");
		}*/
		//vTaskDelay(10);
	}

	vTaskDelete(NULL);
}


int main( void )
{
	int_disable();
	uart_init(115200);
	gpio_mode(0,1);
	gpio_mode(1,1);

	//SimpleQueue = xQueueCreate(5, sizeof (int));
	//xTaskCreate(task1, "Task 1", 100, NULL, 1, NULL);
 	//xTaskCreate(task2, "Task 2", 100, NULL, 1, NULL);
	//vTaskStartScheduler();

	while(1);
	return 0;
}
