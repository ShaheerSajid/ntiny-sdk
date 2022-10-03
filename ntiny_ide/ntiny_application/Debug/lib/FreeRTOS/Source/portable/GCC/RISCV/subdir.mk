################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/FreeRTOS/Source/portable/GCC/RISCV/port.c 

S_UPPER_SRCS += \
../lib/FreeRTOS/Source/portable/GCC/RISCV/portasm.S 

OBJS += \
./lib/FreeRTOS/Source/portable/GCC/RISCV/port.o \
./lib/FreeRTOS/Source/portable/GCC/RISCV/portasm.o 

S_UPPER_DEPS += \
./lib/FreeRTOS/Source/portable/GCC/RISCV/portasm.d 

C_DEPS += \
./lib/FreeRTOS/Source/portable/GCC/RISCV/port.d 


# Each subdirectory must supply rules for building sources it contributes
lib/FreeRTOS/Source/portable/GCC/RISCV/%.o: ../lib/FreeRTOS/Source/portable/GCC/RISCV/%.c lib/FreeRTOS/Source/portable/GCC/RISCV/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g3 -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/bsp/inc" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS/Source/portable/GCC/RISCV" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS/Source" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS/Source/include" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FFT/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/AES/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/ADXL_346/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DAC_MCP4725/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DMD/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/GY80/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/keypad/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/lcd/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MFRC522/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MPU_6050/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/Servo_motor/src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/FreeRTOS/Source/portable/GCC/RISCV/%.o: ../lib/FreeRTOS/Source/portable/GCC/RISCV/%.S lib/FreeRTOS/Source/portable/GCC/RISCV/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


