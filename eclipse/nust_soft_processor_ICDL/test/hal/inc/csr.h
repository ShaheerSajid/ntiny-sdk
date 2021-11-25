/*
 * csr.h
 *
 *  Created on: 25 Nov 2021
 *      Author: shaheer
 */

#ifndef CSR_H_
#define CSR_H_

#ifdef __cplusplus
#define register
#endif
#define __ASM_STR(x) #x
#define csr_swap(csr, val)									              \
({															                          \
	register unsigned long __v = (unsigned long)(val);     	\
	__asm__ __volatile__ ("csrrw %0, " __ASM_STR(csr) ", %1"\
			      : "=r" (__v) : "rK" (__v)					            \
			      : "memory");								                  \
	__v;						                                        \
})

#define csr_read(csr)						                          \
({								                                        \
	register unsigned long __v;				                      \
	__asm__ __volatile__ ("csrr %0, " __ASM_STR(csr)	      \
			      : "=r" (__v) :			                          \
			      : "memory");		                              \
	__v;							                                      \
})

#define csr_write(csr, val)					                      \
({								                                        \
	unsigned long __v = (unsigned long)(val);		            \
	__asm__ __volatile__ ("csrw " __ASM_STR(csr) ", %0"	    \
			      : : "rK" (__v)			                          \
			      : "memory");			                            \
})

#define csr_read_set(csr, val)					                  \
({								                                        \
	unsigned long __v = (unsigned long)(val);		            \
	__asm__ __volatile__ ("csrrs %0, " __ASM_STR(csr) ", %1"\
			      : "=r" (__v) : "rK" (__v)	                  	\
			      : "memory");		                              \
	__v;							                                      \
})

#define csr_set(csr, val)					                        \
({								                                        \
	unsigned long __v = (unsigned long)(val);		            \
	__asm__ __volatile__ ("csrs " __ASM_STR(csr) ", %0"	    \
			      : : "rK" (__v)			                          \
			      : "memory");			                            \
})

#define csr_read_clear(csr, val)				                  \
({								                                        \
	unsigned long __v = (unsigned long)(val);		            \
	__asm__ __volatile__ ("csrrc %0, " __ASM_STR(csr) ", %1"\
			      : "=r" (__v) : "rK" (__v)		                  \
			      : "memory");			                            \
	__v;							                                      \
})

#define csr_clear(csr, val)				  	                    \
({								                                        \
	unsigned long __v = (unsigned long)(val);		            \
	__asm__ __volatile__ ("csrc " __ASM_STR(csr) ", %0"	    \
			      : : "rK" (__v)			                          \
			      : "memory");			                            \
})

#endif /* HAL_INC_CSR_H_ */
