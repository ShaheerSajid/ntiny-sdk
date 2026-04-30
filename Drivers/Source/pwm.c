/*****************************************************************************
 * @file     pwm.c
 * @brief    NTiny PWM peripheral driver.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "pwm.h"

/** Cached pointer to the PWM register block. */
static volatile uint32_t *m_pwm;

void pwm_init(void)
{
    m_pwm = (volatile uint32_t *)pwm_base_addr;
    m_pwm[CONTROL_REG] = 0x0;
}

void set_compare1 (uint32_t v) { m_pwm[COMPARE1_REG]  = v; }
void set_compare2 (uint32_t v) { m_pwm[COMPARE2_REG]  = v; }
void set_prescaler(uint32_t v) { m_pwm[PRESCALER_REG] = v; }
void set_period1  (uint32_t v) { m_pwm[PERIOD1_REG]   = v; }
void set_period2  (uint32_t v) { m_pwm[PERIOD2_REG]   = v; }
void set_deadtime1(uint32_t v) { m_pwm[DEADTIME1_REG] = v; }
void set_deadtime2(uint32_t v) { m_pwm[DEADTIME2_REG] = v; }

void pwm1_start(void) { m_pwm[CONTROL_REG] |=  0x01; }
void pwm2_start(void) { m_pwm[CONTROL_REG] |=  0x02; }
void pwm1_stop (void) { m_pwm[CONTROL_REG] &= ~0x01; }
void pwm2_stop (void) { m_pwm[CONTROL_REG] &= ~0x02; }

uint32_t read_control(void) { return m_pwm[CONTROL_REG]; }

void pwm1_set_mode(int com_re, int center_edge)
{
    /* com_re1 -> bit 2; center_edge1 -> bit 4 */
    if (com_re)      m_pwm[CONTROL_REG] |=  (1u << 2);
    else             m_pwm[CONTROL_REG] &= ~(1u << 2);

    if (center_edge) m_pwm[CONTROL_REG] |=  (1u << 4);
    else             m_pwm[CONTROL_REG] &= ~(1u << 4);
}

void pwm2_set_mode(int com_re, int center_edge)
{
    /* com_re2 -> bit 3; center_edge2 -> bit 5 */
    if (com_re)      m_pwm[CONTROL_REG] |=  (1u << 3);
    else             m_pwm[CONTROL_REG] &= ~(1u << 3);

    if (center_edge) m_pwm[CONTROL_REG] |=  (1u << 5);
    else             m_pwm[CONTROL_REG] &= ~(1u << 5);
}
