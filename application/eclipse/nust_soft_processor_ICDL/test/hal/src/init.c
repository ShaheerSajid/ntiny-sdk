/* Global Variables: */
#define INIT_ASIC 1
  extern __attribute__((section (".reset"), naked))
  void _reset(){
    // setup the stack
    // must needed for both stdlib and newlib versions
    // since newlib assumes that stack has already been setup
	#ifdef INIT_ASIC
      __asm("li  x1, 0");
	  __asm("li  x2, 0");
	  __asm("li  x3, 0");
	  __asm("li  x4, 0");
	  __asm("li  x5, 0");
	  __asm("li  x6, 0");
	  __asm("li  x7, 0");
	  __asm("li  x8, 0");
	  __asm("li  x9, 0");
	  __asm("li x10, 0");
	  __asm("li x11, 0");
	  __asm("li x12, 0");
	  __asm("li x13, 0");
	  __asm("li x14, 0");
	  __asm("li x15, 0");
	  __asm("li x16, 0");
	  __asm("li x17, 0");
	  __asm("li x18, 0");
	  __asm("li x19, 0");
	  __asm("li x20, 0");
	  __asm("li x21, 0");
	  __asm("li x22, 0");
	  __asm("li x23, 0");
	  __asm("li x24, 0");
	  __asm("li x25, 0");
	  __asm("li x26, 0");
	  __asm("li x27, 0");
	  __asm("li x28, 0");
	  __asm("li x29, 0");
	  __asm("li x30, 0");
	  __asm("li x31, 0");
	#endif
    __asm(".option push\n"
          ".option norelax\n"
          "la gp, __global_pointer$\n"
          ".option pop");
    __asm("la sp, __stack_top");
    __asm("add s0, sp, zero");
    extern char __bss_start,__BSS_END__;
    char *dst;
    for (dst = &__bss_start; dst< &__BSS_END__; dst++)
    	{
    	*dst = 0;
    	__asm("nop");
    	}
	

  }
