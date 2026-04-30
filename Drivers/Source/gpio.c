/*****************************************************************************
 * @file     gpio.c
 * @brief    NTiny GPIO peripheral driver.
 *
 *           Thin wrapper around the four memory-mapped registers DDR, DOUT,
 *           DIN and CMD. The CMD register is write-strobed: 0x01 resets
 *           DOUT, 0x02 resets DDR, 0x04 resets the entire block, and bit 5
 *           enables the GPIO interrupt source.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "gpio.h"

/** Base of the GPIO peripheral (resolved from the memory map). */
volatile uint32_t *gpio__base_addr = (volatile uint32_t *)GPIO_BASE_ADDR;

void gpio_mode(int pin, uint8_t mode)
{
    if (mode)
        gpio__base_addr[DDR] |=  (1u << pin);  /* output */
    else
        gpio__base_addr[DDR] &= ~(1u << pin);  /* input  */
}

void gpio_write_pin(int pin, uint8_t state)
{
    if (state)
        gpio__base_addr[Dout] |=  (1u << pin);
    else
        gpio__base_addr[Dout] &= ~(1u << pin);
}

int gpio_read_pin(int pin)
{
    return (gpio__base_addr[Din] >> pin) & 1;
}

void gpio_reset(void)      { gpio__base_addr[cmd] = 0x04; }
void gpio_reset_DDR(void)  { gpio__base_addr[cmd] = 0x02; }
void gpio_reset_DOUT(void) { gpio__base_addr[cmd] = 0x01; }

void gpio_set_ddr(uint32_t value) { gpio__base_addr[DDR]  = value; }
void gpio_set    (uint32_t value) { gpio__base_addr[Dout] = value; }

uint32_t gpio_read_all(void)       { return gpio__base_addr[Din]; }
uint32_t gpio_check_pin_mode(void) { return gpio__base_addr[DDR]; }

void gpio_set_interrupt(void)
{
    /* CMD bit 5 = enable GPIO IRQ source. Bit 4 (commented in older code)
     * was the legacy "any-edge" trigger select, kept disabled here. */
    gpio__base_addr[cmd] |= (1u << 5);
}
