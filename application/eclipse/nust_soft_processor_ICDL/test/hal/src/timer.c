#include "timer.h"

#include <stdint.h>
#include <stdio.h>



volatile uint32_t	*timer_base_addr	= 	(volatile uint32_t*)0x200000;

void timer_set_count(int count)
{
	timer_base_addr[Count_Register] = count;
}
void timer_set_prescaler(int pre)
{
	timer_base_addr[CLOCK_Prescaler] = pre - 1;
}
void timer_set_compare(int max_count_value)
{
	timer_base_addr[Compare_Register] = max_count_value;
}
void timer_start( )
{
	timer_base_addr[Control_Register] = 0x2;
}
void timer_stop( )
{
	timer_base_addr[Control_Register] = 0x0;
}

int timer_read_control()
{
	return timer_base_addr[Control_Register];
}
int timer_read_status()
{
	return timer_base_addr[Status_Register];
}
unsigned int timer_read_count_value()
{
	return timer_base_addr[Count_Register];
}
unsigned int timer_read_compare_value()
{
	return timer_base_addr[Compare_Register];
}
int timer_read_prescaler_value()
{
	return timer_base_addr[CLOCK_Prescaler];
}
