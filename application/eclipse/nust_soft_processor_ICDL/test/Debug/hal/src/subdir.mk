################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/src/init.c \
../hal/src/timer.c \
../hal/src/uart.c 

OBJS += \
./hal/src/init.o \
./hal/src/timer.o \
./hal/src/uart.o 

C_DEPS += \
./hal/src/init.d \
./hal/src/timer.d \
./hal/src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
hal/src/%.o: ../hal/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -O3  -g3 -I"/home/shaheer/Documents/GitHub/bare-metal-processor/application/eclipse/nust_soft_processor_ICDL/test/hal/inc" -include"/home/shaheer/Documents/GitHub/bare-metal-processor/application/eclipse/nust_soft_processor_ICDL/test/hal/inc/uart_def.h" -include"/home/shaheer/Documents/GitHub/bare-metal-processor/application/eclipse/nust_soft_processor_ICDL/test/hal/inc/timer.h" -include"/home/shaheer/Documents/GitHub/bare-metal-processor/application/eclipse/nust_soft_processor_ICDL/test/hal/inc/uart.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


