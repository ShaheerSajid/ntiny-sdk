/*****************************************************************************
 * @file     plic.h
 * @brief    Public API for the NTiny Platform-Level Interrupt Controller.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef PLIC_H_
#define PLIC_H_

#include <stdint.h>

/** Set the per-source enable mask. */
void     set_interrupt_enable(uint32_t val);

/** Read the per-source enable mask. */
uint32_t get_interrupt_enable(void);

/** Set the priority threshold (sources with priority > threshold fire). */
void     set_interrupt_threshold(uint32_t val);

/** Read the priority threshold. */
uint32_t get_interrupt_threshold(void);

/** Set the priority for the currently selected source. */
void     set_interrupt_priority(uint32_t val);

/** Read the priority register. */
uint32_t get_interrupt_priority(void);

/** Claim the highest-priority pending interrupt; returns the IRQ ID. */
uint32_t get_interrupt_id(void);

#endif /* PLIC_H_ */
