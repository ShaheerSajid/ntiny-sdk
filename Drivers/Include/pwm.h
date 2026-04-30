/*****************************************************************************
 * @file     pwm.h
 * @brief    Public API and register layout for the NTiny PWM peripheral.
 *
 *           Two independent PWM outputs share the same prescaler. Each
 *           channel has period, compare and dead-time registers. Mode bits
 *           in the control register select edge / centre alignment and a
 *           complementary-redundant output configuration suitable for
 *           half-bridge drivers.
 *
 *           Control register bit map:
 *             [0] pwm1_en
 *             [1] pwm2_en
 *             [2] com_re1     (complementary/redundant for ch1)
 *             [3] com_re2
 *             [4] center_edge1 (1 = centre-aligned, 0 = edge)
 *             [5] center_edge2
 *             [6] inverting1
 *             [7] inverting2
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef __PWM_H__
#define __PWM_H__

#include <stdint.h>
#include "ntiny_mem_map.h"

/* PWM register layout (word-indexed offsets) */
#define PRESCALER_REG  0x00
#define CONTROL_REG    0x01
#define PERIOD1_REG    0x02
#define PERIOD2_REG    0x03
#define COMPARE1_REG   0x04
#define COMPARE2_REG   0x05
#define DEADTIME1_REG  0x06
#define DEADTIME2_REG  0x07

void     pwm_init (void);
void     set_compare1 (uint32_t compare_value);
void     set_compare2 (uint32_t compare_value);
void     set_prescaler(uint32_t prescaler_value);
void     set_period1 (uint32_t period_value);
void     set_period2 (uint32_t period_value);
void     set_deadtime1(uint32_t deadtime);
void     set_deadtime2(uint32_t deadtime);
void     pwm1_start(void);
void     pwm2_start(void);
void     pwm1_stop (void);
void     pwm2_stop (void);
uint32_t read_control(void);
void     pwm1_set_mode(int com_re, int center_edge);
void     pwm2_set_mode(int com_re, int center_edge);

#endif /* __PWM_H__ */
