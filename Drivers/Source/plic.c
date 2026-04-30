/*****************************************************************************
 * @file     plic.c
 * @brief    NTiny PLIC driver.
 *
 *           The PLIC exposes a 32-bit IE mask, a 2-bit threshold, a 15-bit
 *           priority field and a read-only ID claim register. ISR_EXT_ASM
 *           in the startup code typically reads INTERRUPT_ID to dispatch.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "plic.h"
#include "plic_defs.h"

/** Base of the PLIC peripheral. */
volatile uint32_t *plic_base_addr = (volatile uint32_t *)PLIC_BASE_ADDR;

void set_interrupt_enable(uint32_t val)
{
    plic_base_addr[IE_INTERRUPT] = val & 0x1f;
}

uint32_t get_interrupt_enable(void)
{
    return plic_base_addr[IE_INTERRUPT];
}

void set_interrupt_threshold(uint32_t val)
{
    plic_base_addr[THRESHOLD] = val & 0x03;
}

uint32_t get_interrupt_threshold(void)
{
    return plic_base_addr[THRESHOLD];
}

void set_interrupt_priority(uint32_t val)
{
    plic_base_addr[PRIORITY] = val & 0x7FFF;
}

uint32_t get_interrupt_priority(void)
{
    return plic_base_addr[PRIORITY];
}

uint32_t get_interrupt_id(void)
{
    return plic_base_addr[INTERRUPT_ID];
}
