################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio.c \
../src/init.c \
../src/main.c \
../src/timer.c \
../src/uart.c 

OBJS += \
./src/gpio.o \
./src/init.o \
./src/main.o \
./src/timer.o \
./src/uart.o 

C_DEPS += \
./src/gpio.d \
./src/init.d \
./src/main.d \
./src/timer.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -O3  -g3 -I"/home/shaheer/Documents/GitHub/bare-metal-processor/application/eclipse/nust_soft_processor_ICDL/sw/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


