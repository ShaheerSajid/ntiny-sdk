#ifndef SERVO_H
#define SERVO_H

#include <stdint.h>

void init_servo();

uint8_t servo_move_angle(uint16_t angle);

#endif