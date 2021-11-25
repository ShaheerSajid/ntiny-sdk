#ifndef __PWM_H__
#define __PWM_H__

#include <stdint.h>


//-----------------------------------------------------------------
// Memory Mapped Addressing:
//-----------------------------------------------------------------

#define pwm_base_addr 0x2001000
#define PRESCALAR_REG 0x00
#define COMPARE_REG   0x01
#define CONTROL_REG   0x02 
#define PERIOD_REG    0x03 
#define COMPARE1_REG   0x04
//-----------------------------------------------------------------
// Prototypes:
//-----------------------------------------------------------------

void init (void); 

void set_compare (uint32_t comapre_value);

void set_compare1 (uint32_t comapre_value1);

void set_prescaler (uint32_t prescaler_value);

void set_period (uint32_t period_reg_value);

void pwm_start (void);

void pwm_stop (void);

uint32_t read_control ();

void pwm_test (void);

#endif
