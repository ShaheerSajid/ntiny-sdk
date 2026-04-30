/*****************************************************************************
 * @file     timer.h
 * @brief    Public API and register layout for the NTiny timer peripheral.
 *
 *           Timer counts up from 0 with a programmable prescaler. When
 *           COUNT == COMPARE the STATUS.count_complete bit asserts. The
 *           delay helpers chain enough one-shot intervals to approximate
 *           millisecond and microsecond delays at F_CPU = 50 MHz.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include "ntiny_mem_map.h"

/*
 * Timer register layout (word-indexed offsets).
 *   0x0 CLOCK_Prescaler  : prescaler value (clock divider - 1)
 *   0x1 Count_Register   : current 32-bit counter
 *   0x2 Control_Register : [6'b0, en, 1'b0]      (bit 1 enables the counter)
 *   0x3 Status_Register  : [7'b0, count_complete] (bit 0 set when COUNT==COMPARE)
 *   0x4 Compare_Register : compare value
 */
#define CLOCK_Prescaler         0x00
#define Count_Register          0x01
#define Control_Register        0x02
#define Status_Register         0x03
#define Compare_Register        0x04

/** Set the clock prescaler (the driver writes prescaler - 1 internally). */
void         timer_set_prescaler(int);

/** Set the compare value. */
void         timer_set_compare(int);

/** Set the current count value. */
void         timer_set_count(int);

/** Enable the counter. */
void         timer_start(void);

/** Disable the counter. */
void         timer_stop(void);

/** Read the STATUS register (bit 0 = count_complete). */
int          timer_read_status(void);

/** Read the CONTROL register. */
int          timer_read_control(void);

unsigned int timer_read_compare_value(void);
unsigned int timer_read_count_value(void);
int          timer_read_prescaler_value(void);

/** Block for approximately @p ms milliseconds. */
void         delay_ms(uint32_t ms);

/** Block for approximately @p us microseconds. */
void         delay_us(uint32_t us);

#endif /* TIMER_H_ */
