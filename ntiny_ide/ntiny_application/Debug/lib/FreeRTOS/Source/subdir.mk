################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/FreeRTOS/Source/croutine.c \
../lib/FreeRTOS/Source/event_groups.c \
../lib/FreeRTOS/Source/list.c \
../lib/FreeRTOS/Source/queue.c \
../lib/FreeRTOS/Source/stream_buffer.c \
../lib/FreeRTOS/Source/tasks.c \
../lib/FreeRTOS/Source/timers.c 

OBJS += \
./lib/FreeRTOS/Source/croutine.o \
./lib/FreeRTOS/Source/event_groups.o \
./lib/FreeRTOS/Source/list.o \
./lib/FreeRTOS/Source/queue.o \
./lib/FreeRTOS/Source/stream_buffer.o \
./lib/FreeRTOS/Source/tasks.o \
./lib/FreeRTOS/Source/timers.o 

C_DEPS += \
./lib/FreeRTOS/Source/croutine.d \
./lib/FreeRTOS/Source/event_groups.d \
./lib/FreeRTOS/Source/list.d \
./lib/FreeRTOS/Source/queue.d \
./lib/FreeRTOS/Source/stream_buffer.d \
./lib/FreeRTOS/Source/tasks.d \
./lib/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
lib/FreeRTOS/Source/%.o: ../lib/FreeRTOS/Source/%.c lib/FreeRTOS/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g3 -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/bsp/inc" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS/Source/portable/GCC/RISCV" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS/Source" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FreeRTOS/Source/include" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/FFT/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/AES/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/ADXL_346/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DAC_MCP4725/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/DMD/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/GY80/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/keypad/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/lcd/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MFRC522/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/MPU_6050/src" -I"/home/shaheer/Documents/GitHub/application/ntiny_ide/ntiny_application/lib/Servo_motor/src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


