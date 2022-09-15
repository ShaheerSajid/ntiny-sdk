################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include lib/lcd/src/subdir.mk
-include lib/keypad/src/subdir.mk
-include lib/Servo_motor/src/subdir.mk
-include lib/SSD1306/src/subdir.mk
-include lib/MPU_6050/src/subdir.mk
-include lib/MFRC522/src/subdir.mk
-include lib/GY80/src/subdir.mk
-include lib/FFT/src/subdir.mk
-include lib/DMD/src/subdir.mk
-include lib/DAC_MCP4725/src/subdir.mk
-include lib/AES/src/subdir.mk
-include lib/ADXL_346/src/subdir.mk
-include bsp/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ntiny_application
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ntiny_application.hex \

SECONDARY_SIZE += \
ntiny_application.siz \


# All Target
all: main-build

# Main-build Target
main-build: ntiny_application.elf secondary-outputs

# Tool invocations
ntiny_application.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU RISC-V Cross C Linker'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g3 -T "/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/bsp/script/link.ld" -nostartfiles -Xlinker --gc-sections --specs=nosys.specs -o "ntiny_application.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ntiny_application.hex: ntiny_application.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv64-unknown-elf-objcopy -O ihex "ntiny_application.elf"  "ntiny_application.hex"
	@echo 'Finished building: $@'
	@echo ' '

ntiny_application.siz: ntiny_application.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv64-unknown-elf-size --format=berkeley -x --totals "ntiny_application.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) ntiny_application.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
