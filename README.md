# NTiny SDK

Software Development Kit for the **NTiny** RISC-V SoC — packaged as a
CMSIS Pack so it can be imported by Keil µVision, IAR EWARM,
STM32CubeIDE, Eclipse-CDT, VS Code (Cortex-Debug), and any other
toolchain that understands the
[Open-CMSIS-Pack](https://www.open-cmsis-pack.org) format.

The SDK is also drop-in compatible with the GNU MCU Eclipse project
template under [`App/`](App/), and ships with a top-level
[`Makefile`](Makefile) that builds any example with a bare GCC
toolchain — no IDE required.

---

## Repository layout

```
ntiny-sdk/
├── NTiny.NTinySDK.pdsc        # CMSIS Pack descriptor (the manifest)
├── CMSIS/SVD/ntiny.svd        # System View Description (registers + IRQs)
├── Device/NTiny/              # CMSIS-style device package
│   ├── Include/               #   ntiny.h, ntiny_mem_map.h, csr.h, system_ntiny.h, init.h
│   ├── Source/                #   startup_ntiny.c, system_ntiny.c
│   ├── Source/GCC/ntiny.ld    #   GCC linker script (single 32 KB RAM @ 0x80000000)
│   └── Config/ntiny_config.h  #   F_CPU and feature toggles
├── Drivers/                   # Peripheral drivers (GPIO, UART, SPI, I2C,
│   ├── Include/               # Timer, PWM, PLIC). Single source of truth.
│   └── Source/
├── Utilities/                 # ee_printf, clock, conversion helpers
├── Libraries/                 # Third-party / benchmark code
│   ├── coremark/              #   EEMBC CoreMark (with portme)
│   ├── dhrystone/             #   Dhrystone benchmark (dhry_1.c + dhry_2.c)
│   ├── FreeRTOS/              #   FreeRTOS port
│   ├── lcd/, MFRC522/, ...    #   peripheral / shield drivers
├── Examples/                  # Ready-to-build example apps. Each is a
│   ├── Blinky/src/            # thin wrapper that uses Drivers/ + Libraries/.
│   ├── UartHello/src/         #   Built-in: Blinky and UartHello.
│   ├── Boot, Car, CRC, FFT,   #   Migrated from the previous src/ directory:
│   │   FFT_ASIC, FFT_FPGA,    #   each main is now in its own folder.
│   │   IoT, MainTemplate,
│   │   MainNTiny, PID, RFID
├── App/                       # Eclipse (GNU MCU) project template.
│   ├── .project, .cproject    # Tracks Examples/Blinky by default; switch
│   └── .settings              # via `make set-example EXAMPLE=<n>`.
├── Makefile                   # Top-level convenience targets
├── gen_pack.sh                # Builds a redistributable .pack file
└── LICENSE                    # Apache 2.0
```

---

## Quick start

### 1. Build with the included Makefile (no IDE)

Requires `riscv64-unknown-elf-gcc` (or any RV32 GCC; override
`TOOL_PREFIX=` on the command line).

```bash
make help                       # list targets and available examples
make build EXAMPLE=Blinky       # build one example
make build EXAMPLE=UartHello
make pack                       # produce NTiny.NTinySDK.<ver>.pack
```

### 2. Use the Eclipse project

```bash
make eclipse                            # launches Eclipse with this folder as workspace
make set-example EXAMPLE=PID            # point App/ at Examples/PID/src
```

The Eclipse project's source paths are *linked resources* that resolve to
`Device/NTiny/Source`, `Drivers/Source`, `Utilities/Source` and the
selected `Examples/<n>/src` — there is no duplicate copy of the BSP
inside the App folder.

### 3. Import as a CMSIS Pack into another IDE

Run `make pack` and import the resulting `.pack` into your IDE's pack
manager (Keil µVision: **Pack Installer → Import**; STM32CubeIDE:
**Help → Manage Packs**; VS Code: **CMSIS-Pack Manager** extension).
The IDE will surface the device under **NTiny / NTiny Series / NTINY**
with the SVD, drivers and example projects ready to use.

---

## Memory map

Single source of truth: [`Device/NTiny/Include/ntiny_mem_map.h`](Device/NTiny/Include/ntiny_mem_map.h).
Mirrors `design/common/mem_map.json` from the
[ntiny core repository](https://github.com/ntiny/ntiny).

| Region   | Base       | Size       |
|----------|------------|------------|
| RAM      | 0x80000000 | 32 KB      |
| Boot ROM | 0x00001000 |  4 KB      |
| UART     | 0x10000000 |  4 KB      |
| SPI      | 0x10010000 |  4 KB      |
| I2C      | 0x10020000 |  4 KB      |
| GPIO     | 0x10030000 |  4 KB      |
| PWM      | 0x10040000 |  4 KB      |
| TIMER    | 0x10050000 |  4 KB      |
| CRC      | 0x10060000 |  4 KB      |
| CLINT    | 0x02000000 | 64 KB      |
| PLIC     | 0x0C000000 | 16 MB      |

---

## Core features

- **ISA**: RV32IMAFC + Zicsr + Zifencei + Zba + Zbb
- **Privilege modes**: M, S, U with Sv32 MMU
- **FPU**: single-precision (PakFPU); enabled in `system_ntiny.c`
- **Default core clock**: 50 MHz
- **Vectored trap handling**: enabled in
  [`startup_ntiny.c`](Device/NTiny/Source/startup_ntiny.c)
- **Interrupt sources**: CLINT (msip / mtimecmp), PLIC (UART, SPI, I2C,
  GPIO, PWM)

---

## License

Apache 2.0 — see [LICENSE](LICENSE).
