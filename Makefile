# =============================================================================
#  NTiny SDK — top-level Makefile
#
#  Convenience targets for opening the Eclipse project, building examples
#  with the bare GCC toolchain, packaging a CMSIS Pack, switching the
#  active example, and tidying up generated artifacts.
#
#    make help               -- list all targets
#    make eclipse            -- launch Eclipse with this folder as workspace
#    make build              -- build the active example (default: Blinky)
#    make build EXAMPLE=PID  -- build a specific example
#    make set-example EXAMPLE=Blinky  -- switch which example App/ tracks
#    make pack               -- produce a CMSIS Pack (.pack) ready for IDE import
#    make svd-validate       -- syntax-check the SVD file
#    make clean              -- remove build output
#
# =============================================================================

# ---- Toolchain ---------------------------------------------------------------
# Override on the command line, e.g. `make build TOOL_PREFIX=riscv32-unknown-elf-`.
TOOL_PREFIX ?= riscv64-unknown-elf-
CC          := $(TOOL_PREFIX)gcc
LD          := $(TOOL_PREFIX)gcc
OBJCOPY     := $(TOOL_PREFIX)objcopy
SIZE        := $(TOOL_PREFIX)size

# Eclipse launcher; any of these usually works on the user's system.
ECLIPSE     ?= $(shell command -v eclipse || command -v gnumcueclipse || \
                       command -v eclipse-cdt || echo eclipse)

# Default example to build / track in App/.project.
EXAMPLE     ?= Blinky

# ---- Paths -------------------------------------------------------------------
ROOT        := $(abspath .)
DEVICE_DIR  := $(ROOT)/Device/NTiny
DRIVERS_DIR := $(ROOT)/Drivers
UTIL_DIR    := $(ROOT)/Utilities
EXAMPLE_DIR := $(ROOT)/Examples/$(EXAMPLE)/src
BUILD_DIR   := $(ROOT)/build/$(EXAMPLE)
LD_SCRIPT   := $(DEVICE_DIR)/Source/GCC/ntiny.ld

# Optional per-example manifest. If Examples/<EX>/example.mk exists it is
# pulled in here; the only variable it sets is LIBS, a space-separated list
# of folder names under Libraries/ to be added to the include path and
# compiled into this build (e.g. "FFT dht").
LIBS        :=
-include $(ROOT)/Examples/$(EXAMPLE)/example.mk

LIB_INC     := $(foreach lib,$(LIBS),-I$(ROOT)/Libraries/$(lib)/src \
                                     -I$(ROOT)/Libraries/$(lib))
LIB_SRCS    := $(foreach lib,$(LIBS), \
                   $(wildcard $(ROOT)/Libraries/$(lib)/src/*.c) \
                   $(wildcard $(ROOT)/Libraries/$(lib)/*.c))

# ---- Compiler flags ----------------------------------------------------------
ARCH_FLAGS  := -march=rv32imc_zicsr_zba_zbb -mabi=ilp32 -mcmodel=medlow
WARN_FLAGS  := -Wall -Wno-implicit
OPT_FLAGS   := -Os -ffunction-sections -fdata-sections
DEFS        := -DF_CPU=50000000 -DCLOCKS_PER_SEC=50000000

CFLAGS      := $(ARCH_FLAGS) $(WARN_FLAGS) $(OPT_FLAGS) $(DEFS) \
               -I$(DEVICE_DIR)/Include \
               -I$(DEVICE_DIR)/Config  \
               -I$(DRIVERS_DIR)/Include \
               -I$(UTIL_DIR)/Include \
               $(LIB_INC)

LDFLAGS     := $(ARCH_FLAGS) -nostartfiles --specs=nosys.specs \
               -T$(LD_SCRIPT) \
               -Wl,--gc-sections -Wl,-Map=$(BUILD_DIR)/$(EXAMPLE).map

# ---- Sources to compile ------------------------------------------------------
DEVICE_SRCS := $(wildcard $(DEVICE_DIR)/Source/*.c)
DRIVER_SRCS := $(wildcard $(DRIVERS_DIR)/Source/*.c)
UTIL_SRCS   := $(wildcard $(UTIL_DIR)/Source/*.c)
APP_SRCS    := $(wildcard $(EXAMPLE_DIR)/*.c)
SRCS        := $(DEVICE_SRCS) $(DRIVER_SRCS) $(UTIL_SRCS) $(LIB_SRCS) $(APP_SRCS)
OBJS        := $(patsubst $(ROOT)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

ELF         := $(BUILD_DIR)/$(EXAMPLE).elf
BIN         := $(BUILD_DIR)/$(EXAMPLE).bin
HEX         := $(BUILD_DIR)/$(EXAMPLE).hex

# =============================================================================
# Targets
# =============================================================================
.PHONY: help eclipse build pack svd-validate set-example clean distclean

help:
	@echo "ntiny-sdk targets:"
	@echo "  make eclipse                   open Eclipse with this workspace"
	@echo "  make build [EXAMPLE=<name>]    build an example (default: Blinky)"
	@echo "  make set-example EXAMPLE=<n>   switch the example tracked by App/"
	@echo "  make pack                      package a CMSIS .pack file"
	@echo "  make svd-validate              xmllint the SVD file"
	@echo "  make clean                     remove build output"
	@echo "  make distclean                 clean + remove generated .pack"
	@echo ""
	@echo "Available examples:"
	@ls Examples/ 2>/dev/null | sed 's/^/  - /'

eclipse:
	@echo "Launching Eclipse with workspace at $(ROOT)"
	$(ECLIPSE) -data $(ROOT) &

# ---- Build -------------------------------------------------------------------
build: $(BIN) $(HEX)
	@$(SIZE) $(ELF)
	@echo "Built: $(ELF)"

$(BUILD_DIR)/%.o: $(ROOT)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(LD) $(OBJS) $(LDFLAGS) -o $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

# ---- Switch which example the Eclipse project tracks ------------------------
set-example:
	@if [ ! -d Examples/$(EXAMPLE) ]; then \
		echo "error: Examples/$(EXAMPLE) does not exist"; exit 1; fi
	@sed -i.bak -E 's,(Examples/)[^/]+(/src</locationURI>),\1$(EXAMPLE)\2,' \
	    App/.project && rm -f App/.project.bak
	@echo "App/ now tracks Examples/$(EXAMPLE)/src"

# ---- CMSIS Pack --------------------------------------------------------------
pack:
	@./gen_pack.sh

# ---- SVD validation ----------------------------------------------------------
svd-validate:
	@command -v xmllint >/dev/null || \
	    { echo "xmllint not installed (apt install libxml2-utils)"; exit 1; }
	xmllint --noout CMSIS/SVD/ntiny.svd && echo "SVD: well-formed"

# ---- Clean -------------------------------------------------------------------
clean:
	rm -rf build/

distclean: clean
	rm -f *.pack
