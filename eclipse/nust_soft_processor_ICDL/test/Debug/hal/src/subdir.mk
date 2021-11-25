################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/src/gpio.c \
../hal/src/i2c.c \
../hal/src/init.c \
../hal/src/pwm.c \
../hal/src/spi.c \
../hal/src/timer.c \
../hal/src/uart.c 

OBJS += \
./hal/src/gpio.o \
./hal/src/i2c.o \
./hal/src/init.o \
./hal/src/pwm.o \
./hal/src/spi.o \
./hal/src/timer.o \
./hal/src/uart.o 

C_DEPS += \
./hal/src/gpio.d \
./hal/src/i2c.d \
./hal/src/init.d \
./hal/src/pwm.d \
./hal/src/spi.d \
./hal/src/timer.d \
./hal/src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
hal/src/%.o: ../hal/src/%.c hal/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-inline-functions  -g3 -I"/home/shaheer/Documents/GitHub/bare-metal-processor/application/eclipse/nust_soft_processor_ICDL/test/hal/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


