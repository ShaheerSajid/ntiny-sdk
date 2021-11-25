#include "pwm.h"
#include <stdint.h>

//-----------------------------------------------------------------
// Locals
//-----------------------------------------------------------------
static volatile uint32_t *m_pwm;

//-----------------------------------------------------------------
// init: setting memory mapped based address of pwm.
//-----------------------------------------------------------------
void init (void)
{
	m_pwm = ( uint32_t *)pwm_base_addr;
	m_pwm[CONTROL_REG] =  0x0;
}


//-----------------------------------------------------------------
// set_compare: setting value of pwm comapre register
//-----------------------------------------------------------------
void set_compare (uint32_t comapre_value)
{
	m_pwm[COMPARE_REG] =  comapre_value;
}

//-----------------------------------------------------------------
// set_compare1: setting value of pwm comapre1 register
//-----------------------------------------------------------------
void set_compare1 (uint32_t comapre_value1)
{
	m_pwm[COMPARE1_REG] =  comapre_value1;
}

//-----------------------------------------------------------------
// set_prescaler: setting value of pwm prescaler register
//-----------------------------------------------------------------
void set_prescaler (uint32_t prescaler_value)
{
	m_pwm[PRESCALAR_REG] =  prescaler_value;
}

//-----------------------------------------------------------------
// set_period: setting value of pwm period register
//-----------------------------------------------------------------
void set_period (uint32_t period_reg_value)
{
	m_pwm[PERIOD_REG] =  period_reg_value;
}

//-----------------------------------------------------------------
// start: setting value of pwm control register
//-----------------------------------------------------------------
void pwm_start ()
{
	m_pwm[CONTROL_REG] =  0x1;
}


//-----------------------------------------------------------------
//  stop: setting value of pwm control register
//-----------------------------------------------------------------
void pwm_stop ()
{
	m_pwm[CONTROL_REG] =  0x0;
}


//-----------------------------------------------------------------
//  read_control: reading value of pwm control register
//-----------------------------------------------------------------
uint32_t read_control ()
{
	return m_pwm[CONTROL_REG];
}


