/*****************************************************************************
 * @file     gpio.h
 * @brief    Public API for the NTiny GPIO driver.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include "gpio_defs.h"

/** Configure direction of a single pin (1 = output, 0 = input). */
void     gpio_mode(int pin, uint8_t mode);

/** Drive a single output pin high (1) or low (0). */
void     gpio_write_pin(int pin, uint8_t state);

/** Read the current state of one input pin. */
int      gpio_read_pin(int pin);

/** Strobe the master reset bit; clears DDR, DOUT, and pending IRQs. */
void     gpio_reset(void);

/** Strobe the DDR-only reset bit. */
void     gpio_reset_DDR(void);

/** Strobe the DOUT-only reset bit. */
void     gpio_reset_DOUT(void);

/** Write all output pins simultaneously. */
void     gpio_set(uint32_t value);

/** Configure direction for all pins simultaneously. */
void     gpio_set_ddr(uint32_t value);

/** Read all input pins as one 32-bit word. */
uint32_t gpio_read_all(void);

/** Read the current DDR (direction) register. */
uint32_t gpio_check_pin_mode(void);

/** Enable the GPIO interrupt source in the peripheral. */
void     gpio_set_interrupt(void);

#endif /* GPIO_H_ */
