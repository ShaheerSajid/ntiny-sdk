################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp/src/clock.c \
../bsp/src/cvt.c \
../bsp/src/ee_printf.c \
../bsp/src/gpio.c \
../bsp/src/i2c.c \
../bsp/src/init.c \
../bsp/src/pwm.c \
../bsp/src/spi.c \
../bsp/src/timer.c \
../bsp/src/uart.c 

OBJS += \
./bsp/src/clock.o \
./bsp/src/cvt.o \
./bsp/src/ee_printf.o \
./bsp/src/gpio.o \
./bsp/src/i2c.o \
./bsp/src/init.o \
./bsp/src/pwm.o \
./bsp/src/spi.o \
./bsp/src/timer.o \
./bsp/src/uart.o 

C_DEPS += \
./bsp/src/clock.d \
./bsp/src/cvt.d \
./bsp/src/ee_printf.d \
./bsp/src/gpio.d \
./bsp/src/i2c.d \
./bsp/src/init.d \
./bsp/src/pwm.d \
./bsp/src/spi.d \
./bsp/src/timer.d \
./bsp/src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/src/%.o: ../bsp/src/%.c bsp/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g3 -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/bsp/inc" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FFT/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/AES/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/ADXL_346/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DAC_MCP4725/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DMD/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/GY80/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/keypad/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/lcd/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MFRC522/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MPU_6050/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/Servo_motor/src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


