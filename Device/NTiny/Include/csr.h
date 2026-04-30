/*****************************************************************************
 * @file     csr.h
 * @brief    RISC-V CSR access macros.
 * @version  1.0.0
 *
 *           These are the standard inline-assembly CSR accessor macros used
 *           throughout the NTiny BSP. They lower to the corresponding
 *           csrr / csrw / csrrs / csrrc instructions and serialise the
 *           compiler's view of memory via "memory" clobbers.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef NTINY_CSR_H
#define NTINY_CSR_H

#ifdef __cplusplus
#define register
#endif

#define __ASM_STR(x) #x

/** Atomic read-then-write of @p csr; returns previous value. */
#define csr_swap(csr, val)                                                   \
({                                                                           \
    register unsigned long __v = (unsigned long)(val);                       \
    __asm__ __volatile__ ("csrrw %0, " __ASM_STR(csr) ", %1"                 \
                          : "=r" (__v) : "rK" (__v) : "memory");             \
    __v;                                                                     \
})

/** Read a CSR. */
#define csr_read(csr)                                                        \
({                                                                           \
    register unsigned long __v;                                              \
    __asm__ __volatile__ ("csrr %0, " __ASM_STR(csr)                         \
                          : "=r" (__v) : : "memory");                        \
    __v;                                                                     \
})

/** Write a CSR. */
#define csr_write(csr, val)                                                  \
({                                                                           \
    unsigned long __v = (unsigned long)(val);                                \
    __asm__ __volatile__ ("csrw " __ASM_STR(csr) ", %0"                      \
                          : : "rK" (__v) : "memory");                        \
})

/** Atomic read-then-set of @p csr; returns previous value. */
#define csr_read_set(csr, val)                                               \
({                                                                           \
    unsigned long __v = (unsigned long)(val);                                \
    __asm__ __volatile__ ("csrrs %0, " __ASM_STR(csr) ", %1"                 \
                          : "=r" (__v) : "rK" (__v) : "memory");             \
    __v;                                                                     \
})

/** Set bits in a CSR (no read-back). */
#define csr_set(csr, val)                                                    \
({                                                                           \
    unsigned long __v = (unsigned long)(val);                                \
    __asm__ __volatile__ ("csrs " __ASM_STR(csr) ", %0"                      \
                          : : "rK" (__v) : "memory");                        \
})

/** Atomic read-then-clear of @p csr; returns previous value. */
#define csr_read_clear(csr, val)                                             \
({                                                                           \
    unsigned long __v = (unsigned long)(val);                                \
    __asm__ __volatile__ ("csrrc %0, " __ASM_STR(csr) ", %1"                 \
                          : "=r" (__v) : "rK" (__v) : "memory");             \
    __v;                                                                     \
})

/** Clear bits in a CSR (no read-back). */
#define csr_clear(csr, val)                                                  \
({                                                                           \
    unsigned long __v = (unsigned long)(val);                                \
    __asm__ __volatile__ ("csrc " __ASM_STR(csr) ", %0"                      \
                          : : "rK" (__v) : "memory");                        \
})

#endif /* NTINY_CSR_H */
