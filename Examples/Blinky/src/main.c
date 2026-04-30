/*****************************************************************************
 * @file     main.c  (Examples/Blinky)
 * @brief    Toggle GPIO pin 0 once per second.
 *
 *           Smallest possible program that exercises the NTiny SDK:
 *           SystemInit() runs from the startup file; main() configures
 *           one GPIO as output and toggles it via the timer-driven
 *           delay_ms() helper.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "ntiny.h"
#include "gpio.h"
#include "timer.h"

#define LED_PIN    0

int main(void)
{
    gpio_mode(LED_PIN, 1);          /* configure as output */

    while (1) {
        gpio_write_pin(LED_PIN, 1);
        delay_ms(500);
        gpio_write_pin(LED_PIN, 0);
        delay_ms(500);
    }
}
