################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/car_main.c 

OBJS += \
./src/car_main.o 

C_DEPS += \
./src/car_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g3 -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/bsp/inc" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FFT/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/AES/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/ADXL_346/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DAC_MCP4725/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DMD/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/GY80/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/keypad/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/lcd/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MFRC522/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MPU_6050/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/Servo_motor/src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


