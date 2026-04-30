/*****************************************************************************
 * @file     ntiny.h
 * @brief    CMSIS-style top-level device header for the NTiny RISC-V SoC.
 * @version  1.0.0
 * @date     2026-04-30
 *
 *           This is the canonical entry point for application code. Pull in
 *           ntiny.h and you get the memory map, peripheral register layouts,
 *           CSR helpers, IRQ numbers, and the SystemInit / SystemCoreClock
 *           interface.
 *
 *           ISA: RV32IMAFC + Zicsr + Zifencei + Zba + Zbb
 *           Modes: M, S, U   |   MMU: Sv32   |   Endian: little
 *           FPU: Single-precision (PakFPU)   |   Default clock: 50 MHz
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef NTINY_H
#define NTINY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ntiny_mem_map.h"
#include "ntiny_config.h"
#include "csr.h"
#include "system_ntiny.h"

/* ==========================================================================
 * IRQ source enumeration (matches PLIC IE_INTERRUPT bit positions)
 * ==========================================================================*/
typedef enum {
    UART_IRQn       = NTINY_IRQ_UART,
    SPI_IRQn        = NTINY_IRQ_SPI,
    I2C_IRQn        = NTINY_IRQ_I2C,
    GPIO_IRQn       = NTINY_IRQ_GPIO,
    PWM_IRQn        = NTINY_IRQ_PWM,
} IRQn_Type;

/* ==========================================================================
 * Peripheral register structures (CMSIS device-header style)
 * Pointer to these is materialised below via the *_BASE macros.
 * ==========================================================================*/
#ifndef __IO
  #define __IO  volatile
#endif
#ifndef __I
  #define __I   volatile const
#endif
#ifndef __O
  #define __O   volatile
#endif

/** GPIO peripheral register block. */
typedef struct {
    __IO uint32_t DDR;     /*!< 0x00 Data direction (1 = output)            */
    __IO uint32_t DOUT;    /*!< 0x04 Data output                            */
    __I  uint32_t DIN;     /*!< 0x08 Data input  (read-only)                */
    __O  uint32_t CMD;     /*!< 0x0C Command (reset/IRQ enable strobes)     */
} GPIO_TypeDef;

/** UART peripheral register block. */
typedef struct {
    __I  uint32_t RX;      /*!< 0x00 Received byte                          */
    __O  uint32_t TX;      /*!< 0x04 Transmit byte                          */
    __I  uint32_t STATUS;  /*!< 0x08 [4]IE [3]TXFULL [2]TXEMPTY [1]RXFULL [0]RXVALID */
    __IO uint32_t CONTROL; /*!< 0x0C [4]IE [1]RST_RX [0]RST_TX              */
    __IO uint32_t BAUDRATE;/*!< 0x10 Baud divisor = (F_CPU / baud) - 1      */
} UART_TypeDef;

/** Timer peripheral register block. */
typedef struct {
    __IO uint32_t PRESCALER; /*!< 0x00 Clock divider - 1                    */
    __IO uint32_t COUNT;     /*!< 0x04 Free-running counter                 */
    __IO uint32_t CONTROL;   /*!< 0x08 [1] enable                           */
    __I  uint32_t STATUS;    /*!< 0x0C [0] count_complete                   */
    __IO uint32_t COMPARE;   /*!< 0x10 Compare value                        */
} TIMER_TypeDef;

/** I2C peripheral register block. */
typedef struct {
    __IO uint32_t CLK_PRESCALER;/*!< 0x00 Clock divider                     */
    __IO uint32_t CTRL;         /*!< 0x04 [7]I2C_EN [6]IRQ_EN               */
    __I  uint32_t RX;           /*!< 0x08 Received byte                     */
    __I  uint32_t STATUS;       /*!< 0x0C Status flags                      */
    __O  uint32_t TX;           /*!< 0x10 Byte to transmit                  */
    __O  uint32_t CMD;          /*!< 0x14 Command (start/stop/r/w/ack/irq)  */
} I2C_TypeDef;

/** PWM peripheral register block. */
typedef struct {
    __IO uint32_t PRESCALER; /*!< 0x00                                      */
    __IO uint32_t CONTROL;   /*!< 0x04 enables / mode bits                  */
    __IO uint32_t PERIOD1;   /*!< 0x08                                      */
    __IO uint32_t PERIOD2;   /*!< 0x0C                                      */
    __IO uint32_t COMPARE1;  /*!< 0x10                                      */
    __IO uint32_t COMPARE2;  /*!< 0x14                                      */
    __IO uint32_t DEADTIME1; /*!< 0x18                                      */
    __IO uint32_t DEADTIME2; /*!< 0x1C                                      */
} PWM_TypeDef;

/** PLIC peripheral register block. */
typedef struct {
    __IO uint32_t IE_INTERRUPT; /*!< 0x00 Interrupt enable mask             */
    __IO uint32_t THRESHOLD;    /*!< 0x04 Priority threshold                */
    __IO uint32_t PRIORITY;     /*!< 0x08 Per-source priority               */
    __I  uint32_t INTERRUPT_ID; /*!< 0x0C Read claims pending IRQ           */
} PLIC_TypeDef;

/* ==========================================================================
 * Peripheral instance pointers
 * ==========================================================================*/
#define GPIO            ((GPIO_TypeDef  *) NTINY_GPIO_BASE)
#define UART            ((UART_TypeDef  *) NTINY_UART_BASE)
#define TIMER           ((TIMER_TypeDef *) NTINY_TIMER_BASE)
#define I2C             ((I2C_TypeDef   *) NTINY_I2C_BASE)
#define PWM             ((PWM_TypeDef   *) NTINY_PWM_BASE)
#define PLIC            ((PLIC_TypeDef  *) NTINY_PLIC_BASE)

/* ==========================================================================
 * RISC-V mie / mip bits
 * ==========================================================================*/
#define NTINY_MIE_MSIE      (1u << 3)   /*!< Machine software interrupt enable*/
#define NTINY_MIE_MTIE      (1u << 7)   /*!< Machine timer    interrupt enable*/
#define NTINY_MIE_MEIE      (1u << 11)  /*!< Machine external interrupt enable*/

#define NTINY_MSTATUS_MIE   (1u << 3)
#define NTINY_MSTATUS_FS    (1u << 13)  /*!< Initial state for FPU enable     */

#ifdef __cplusplus
}
#endif

#endif /* NTINY_H */
