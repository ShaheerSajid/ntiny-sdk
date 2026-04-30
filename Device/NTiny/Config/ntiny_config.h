/*****************************************************************************
 * @file     ntiny_config.h
 * @brief    Per-application configuration for the NTiny SDK.
 * @version  1.0.0
 *
 *           Copy this file into your project, then edit the values to match
 *           your hardware target. Driver source treats these as defaults
 *           with #ifndef guards so you can override per build.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef NTINY_CONFIG_H
#define NTINY_CONFIG_H

/** CPU clock in Hz. Used by uart_init(), I2C_init(), delay_*, etc. */
#ifndef F_CPU
#define F_CPU                 50000000u
#endif

/** Default UART baud rate for the SDK examples. */
#ifndef NTINY_DEFAULT_BAUD
#define NTINY_DEFAULT_BAUD    115200u
#endif

/** Set to 1 if running under the Verilator simulator. Some drivers skip
 *  fuller status polling under simulation to keep cycle counts low.        */
#ifndef NTINY_VERILATOR
#define NTINY_VERILATOR       0
#endif

#endif /* NTINY_CONFIG_H */
