#ifndef __dht_
#define __dht_

#include <stdint.h>
#include "gpio.h"
#include "timer.h"
#include "ee_printf.h"


//------------------------ Global variable ----------------------//
#define OUTPUT 1
#define INPUT 0
#define LOW 0
#define HIGH 1

#define MAXTIMINGS	85


//---------------------- Function prototypes -------------------//

void dht_pin_init(int pin);            //use this function to declare dht pin

int dht_read(float *temp, float *humid);           //returns 1 if data is valid



#endif