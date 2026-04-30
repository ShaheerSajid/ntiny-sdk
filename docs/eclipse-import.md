# Eclipse: NTiny SDK CMSIS-Pack import — step-by-step

This guide walks through the **one-time** setup needed to build NTiny
projects in Eclipse Embedded CDT using the
ARM **CmsisPackPlugIn** for pack management. Once a project builds,
you can copy its settings to any new project — no further per-project
clicks needed.

> **Why is this manual at all?** The legacy CMSIS-Pack 1.x format does
> not carry GCC compiler/linker flags portably; ARM's plugin only
> auto-wires Keil µVision project files. Open-CMSIS-Toolbox
> (`csolution.yml` + `cbuild`) fixes this — see
> [csolution path](#alternative-csolution--cbuild). For Eclipse today,
> the steps below are needed.

---

## 0. Prerequisites

- Eclipse Embedded CDT (the *embedcpp* package) — `~/eclipse/embedcpp-2025-09/eclipse/`
- ARM CmsisPackPlugIn 2.10+ (install via *Help → Install New Software → Add → Archive…* and pick `CmsisPackPlugIn2.10.0.zip`)
- RISC-V GCC at `/opt/riscv/bin` (or anywhere; just remember the path)
- This SDK's pack at `~/Documents/github/ntiny-sdk/NTiny.NTinySDK.<ver>.pack`
  — produce it with `make pack` from the SDK root.

## 1. Install the pack

The plugin's *local pack repository* defaults to `~/.local/cmsis-packs/`.

```bash
# From the SDK root
make pack                                            # builds NTiny.NTinySDK.<ver>.pack
mkdir -p ~/.local/cmsis-packs/NTiny/NTinySDK/1.0.0
cd       ~/.local/cmsis-packs/NTiny/NTinySDK/1.0.0
unzip -oq ~/Documents/github/ntiny-sdk/NTiny.NTinySDK.1.0.0.pack
cp NTiny.NTinySDK.pdsc ~/.local/cmsis-packs/.cache/
```

In Eclipse:

1. **Window → Show View → Other → CMSIS → Packs / Devices / Boards / Examples** (open all four).
2. In **Packs** view click the **Refresh** button. NTiny / NTinySDK 1.0.0 should appear.
3. **Devices** view: expand `NTiny → NTiny Series → NTINY`.

## 2. Create the project

1. **File → New → C Project → CMSIS C/C++ Project** (created by the
   ARM plugin). Name it e.g. `ntiny_blinky`. **Next**.
2. **Device picker:** expand to `NTiny → NTINY` and select it. **Next**.
3. **RTE Configuration page** appears. Tick the components you need
   (for Blinky: `Device → Startup`, `Driver → GPIO`, `Driver → Timer`).
   The **Resolve** button stays grey when everything's already
   consistent — that's the green-light state. **Ctrl+S** to save.
4. **Finish**.

Eclipse drops the selected component files into `RTE/`:

```
ntiny_blinky/
├── RTE/
│   ├── Device/NTINY/
│   │   ├── startup_ntiny.c
│   │   ├── system_ntiny.c
│   │   ├── ntiny.ld
│   │   ├── ntiny_config.h
│   │   ├── csr.h
│   │   └── init.h
│   ├── Driver/
│   │   ├── gpio.c, gpio.h, gpio_defs.h
│   │   └── timer.c, timer.h
│   └── RTE_Components.h
└── ntiny.rteconfig
```

## 3. Add the application source

1. Right-click the project → **New → Folder** → `src` → Finish.
2. Right-click `src` → **Import → General → File System → Next**.
3. Browse to `<SDK>/Examples/Blinky/src/`, tick `main.c`, **Finish**.

(Substitute any other `Examples/<name>/src/` to build a different
example.)

## 4. Build settings — the manual checklist

Open **Project → Properties → C/C++ Build → Settings → Tool Settings**.

### Target Processor

| Setting | Value |
|---|---|
| Architecture | RV32I |
| Multiply extension (RVM) | ✅ |
| Compressed extension (RVC) | ✅ |
| Atomic extension (RVA) | ☐ |
| Floating point | none |
| Integer ABI | `ilp32` |
| Floating point ABI | none |
| Other extensions | `_zicsr_zba_zbb` |

### Cross GCC Compiler → Includes

The RTE include path is added automatically. No extras needed for
Blinky. (For examples that use `Libraries/<x>/`, add
`${ProjDirPath}/Libraries/<x>/src` here.)

### Cross GCC Compiler → Preprocessor → Defined symbols (-D)

| Symbol |
|---|
| `F_CPU=50000000` |
| `CLOCKS_PER_SEC=50000000` |

### Cross GCC Linker → General

| Setting | Value |
|---|---|
| Remove unused sections (-Xlinker --gc-sections) | ✅ |
| Do not use standard start files (-nostartfiles) | ✅ |
| Do not use syscalls (--specs=nosys.specs) | ✅ |
| Use newlib-nano (--specs=nano.specs) | ☐ |
| **Script files (-T)** — click + and add | `${ProjDirPath}/RTE/Device/NTINY/ntiny.ld` |

### Toolchains tab

| Setting | Value |
|---|---|
| Prefix | `riscv64-unknown-elf-` |
| Path | `/opt/riscv/bin` |

Click **Apply and Close**.

## 5. Build

**Project → Clean → Build**, or just `Ctrl+B`.

Console should end with something like:

```
text   data    bss    dec    hex   filename
 436    12      0    448   1c0   ntiny_blinky.elf
```

If you see **`undefined reference to __stack_top`** or **`undefined
reference to main`**, recheck steps 3 and 4 — those are the
fingerprints of a missing linker script or a missing `main.c`.

## 6. Reuse for the next example

Two ways:

1. **Duplicate the project** in Project Explorer (Copy + Paste, give a
   new name). The build settings carry over; just swap out
   `src/main.c` for the one from the Examples folder you want.
2. **Repeat steps 2–4** but tick different RTE components. The
   per-example component checklist matches the
   [`<example>` blocks in the PDSC](../NTiny.NTinySDK.pdsc).

## Alternative: csolution + cbuild

If your tooling supports Open-CMSIS-Toolbox:

```bash
# Install cbuild (one-time)
curl -L https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases/latest/download/cmsis-toolbox-linux-amd64.tar.gz \
    | tar -xz -C /opt/cmsis-toolbox
export PATH=/opt/cmsis-toolbox/bin:$PATH

# From the SDK root
cd Examples/Blinky
cbuild Blinky.csolution.yml
```

This consumes [`Examples/Blinky/Blinky.csolution.yml`][csolution] and
[`Blinky.cproject.yml`][cproject], which carry every flag we set
manually above. No per-project Eclipse clicks needed.

[csolution]: ../Examples/Blinky/Blinky.csolution.yml
[cproject]:  ../Examples/Blinky/Blinky.cproject.yml
