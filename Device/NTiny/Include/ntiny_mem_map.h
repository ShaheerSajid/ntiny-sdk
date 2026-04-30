/*****************************************************************************
 * @file     ntiny_mem_map.h
 * @brief    NTiny SoC memory map and peripheral base addresses.
 * @version  1.0.0
 *
 *           Single source of truth for all memory-mapped addresses in the
 *           NTiny SDK. Mirrors design/common/mem_map.json from the ntiny
 *           core repository.
 *
 *           Naming convention:
 *             NTINY_<periph>_BASE      -- canonical macro
 *             <periph>_BASE_ADDR       -- legacy alias (preserved for
 *                                         compatibility with older code)
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef NTINY_MEM_MAP_H
#define NTINY_MEM_MAP_H

/* ==========================================================================
 * Memory regions
 * ==========================================================================*/
#define NTINY_RAM_BASE          0x80000000u   /*!< 32 KB unified RAM        */
#define NTINY_RAM_SIZE_BYTES    0x00008000u

#define NTINY_BOOT_BASE         0x00001000u   /*!< 4 KB boot ROM            */
#define NTINY_BOOT_SIZE_BYTES   0x00001000u

/* ==========================================================================
 * Memory-mapped peripherals (each at a 0x10000 stride; 4 KB window)
 * ==========================================================================*/
#define NTINY_UART_BASE         0x10000000u   /*!< UART  */
#define NTINY_SPI_BASE          0x10010000u   /*!< SPI   */
#define NTINY_I2C_BASE          0x10020000u   /*!< I2C   */
#define NTINY_GPIO_BASE         0x10030000u   /*!< GPIO  */
#define NTINY_PWM_BASE          0x10040000u   /*!< PWM   */
#define NTINY_TIMER_BASE        0x10050000u   /*!< Timer */
#define NTINY_CRC_BASE          0x10060000u   /*!< CRC   */

/* ==========================================================================
 * Interrupt controllers (RISC-V SiFive-style)
 * ==========================================================================*/
#define NTINY_CLINT_BASE        0x02000000u   /*!< Core-local interrupts (64 KB)  */
#define NTINY_PLIC_BASE         0x0C000000u   /*!< Platform-level interrupts (16 MB)*/

/* CLINT register offsets */
#define NTINY_CLINT_MSIP        (NTINY_CLINT_BASE + 0x0000u) /*!< Software interrupt pending */
#define NTINY_CLINT_MTIMECMP    (NTINY_CLINT_BASE + 0x4000u) /*!< 64-bit mtimecmp            */
#define NTINY_CLINT_MTIME       (NTINY_CLINT_BASE + 0xBFF8u) /*!< 64-bit mtime (free-running)*/

/* ==========================================================================
 * Special: simulation soft-int trigger and host exit
 * ==========================================================================*/
#define NTINY_SOFT_INT_ADDR     0x10070000u
#define NTINY_TOHOST_ADDR       0x0F000000u

/* ==========================================================================
 * PLIC IRQ source IDs
 *  Bit position in the PLIC IE_INTERRUPT register matches these IDs.
 * ==========================================================================*/
#define NTINY_IRQ_UART          0u
#define NTINY_IRQ_SPI           1u
#define NTINY_IRQ_I2C           2u
#define NTINY_IRQ_GPIO          3u
#define NTINY_IRQ_PWM           4u

/* ==========================================================================
 * Backward-compatible aliases used by the legacy driver implementations.
 * ==========================================================================*/
#ifndef UART_BASE_ADDR
  #define UART_BASE_ADDR        NTINY_UART_BASE
#endif
#ifndef SPI_BASE_ADDR
  #define SPI_BASE_ADDR         NTINY_SPI_BASE
#endif
#ifndef I2C_BASE_ADDR
  #define I2C_BASE_ADDR         NTINY_I2C_BASE
#endif
#ifndef BASE_ADDR
  #define BASE_ADDR             NTINY_I2C_BASE   /* legacy I2C symbol */
#endif
#ifndef GPIO_BASE_ADDR
  #define GPIO_BASE_ADDR        NTINY_GPIO_BASE
#endif
#ifndef TIMER_BASE_ADDR
  #define TIMER_BASE_ADDR       NTINY_TIMER_BASE
#endif
#ifndef PLIC_BASE_ADDR
  #define PLIC_BASE_ADDR        NTINY_PLIC_BASE
#endif
#ifndef pwm_base_addr
  #define pwm_base_addr         NTINY_PWM_BASE
#endif

#endif /* NTINY_MEM_MAP_H */
