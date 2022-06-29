#include <time.h>
#include "csr.h"


clock_t clock()
{
	unsigned long long cycles = csr_read(mcycleh);
  	cycles = (cycles << 32) + csr_read(mcycle);
  	return (clock_t)cycles;
}
