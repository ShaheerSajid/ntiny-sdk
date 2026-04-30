/*****************************************************************************
 * @file     timer.c
 * @brief    NTiny timer peripheral driver.
 *
 *           delay_ms/delay_us each set up a one-shot interval and then
 *           busy-wait on the count_complete flag, repeating once per
 *           millisecond / microsecond. They assume F_CPU = 50 MHz; for
 *           other clocks the COMPARE values would need scaling.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "timer.h"

/** Base of the timer peripheral. */
volatile uint32_t *timer_base_addr = (volatile uint32_t *)TIMER_BASE_ADDR;

void timer_set_count(int count)
{
    timer_base_addr[Count_Register] = count;
}

void timer_set_prescaler(int pre)
{
    /* The hardware divides by (prescaler + 1). Take user-friendly input. */
    timer_base_addr[CLOCK_Prescaler] = pre - 1;
}

void timer_set_compare(int max_count_value)
{
    timer_base_addr[Compare_Register] = max_count_value;
}

void timer_start(void) { timer_base_addr[Control_Register] = 0x2; }
void timer_stop (void) { timer_base_addr[Control_Register] = 0x0; }

int timer_read_control(void) { return timer_base_addr[Control_Register]; }
int timer_read_status (void) { return timer_base_addr[Status_Register];  }

unsigned int timer_read_count_value  (void) { return timer_base_addr[Count_Register]; }
unsigned int timer_read_compare_value(void) { return timer_base_addr[Compare_Register]; }
int          timer_read_prescaler_value(void) { return timer_base_addr[CLOCK_Prescaler]; }

void delay_ms(uint32_t ms_delay_value)
{
    for (uint32_t i = 0; i < ms_delay_value; i++) {
        timer_set_prescaler(1);
        timer_set_compare(50000);   /* 50 MHz / 1 / 50000 = 1 ms */
        timer_set_count(0);
        timer_start();
        while (timer_read_status() == 0) {
        }
        timer_stop();
    }
}

void delay_us(uint32_t us_delay_value)
{
    for (uint32_t i = 0; i < us_delay_value; i++) {
        timer_set_prescaler(1);
        timer_set_compare(50);      /* 50 MHz / 1 / 50 = 1 us */
        timer_set_count(0);
        timer_start();
        while (timer_read_status() == 0) {
        }
        timer_stop();
    }
}
