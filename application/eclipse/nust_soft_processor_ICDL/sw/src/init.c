/* Global Variables: */
#define INIT_ASIC 1
  extern __attribute__((section (".reset"), naked))
  void _reset(){
    // setup the stack
    // must needed for both stdlib and newlib versions
    // since newlib assumes that stack has already been setup
	#ifdef INIT_ASIC
      __asm("mv  x1, x0");
	  __asm("mv  x2, x1");
	  __asm("mv  x3, x1");
	  __asm("mv  x4, x1");
	  __asm("mv  x5, x1");
	  __asm("mv  x6, x1");
	  __asm("mv  x7, x1");
	  __asm("mv  x8, x1");
	  __asm("mv  x9, x1");
	  __asm("mv x10, x1");
	  __asm("mv x11, x1");
	  __asm("mv x12, x1");
	  __asm("mv x13, x1");
	  __asm("mv x14, x1");
	  __asm("mv x15, x1");
	  __asm("mv x16, x1");
	  __asm("mv x17, x1");
	  __asm("mv x18, x1");
	  __asm("mv x19, x1");
	  __asm("mv x20, x1");
	  __asm("mv x21, x1");
	  __asm("mv x22, x1");
	  __asm("mv x23, x1");
	  __asm("mv x24, x1");
	  __asm("mv x25, x1");
	  __asm("mv x26, x1");
	  __asm("mv x27, x1");
	  __asm("mv x28, x1");
	  __asm("mv x29, x1");
	  __asm("mv x30, x1");
	  __asm("mv x31, x1");
	#endif
    __asm(".option push\n"
          ".option norelax\n"
          "la gp, __global_pointer$\n"
          ".option pop");
    __asm("la sp, __stack_top");
    __asm("add s0, sp, zero");
	

  }
