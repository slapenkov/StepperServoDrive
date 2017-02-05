################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BlinkLed.c \
../src/Joistick.c \
../src/LedPwm.c \
../src/Timer.c \
../src/_write.c \
../src/main.c 

C_DEPS += \
./src/BlinkLed.d \
./src/Joistick.d \
./src/LedPwm.d \
./src/Timer.d \
./src/_write.d \
./src/main.d 

OBJS += \
./src/BlinkLed.o \
./src/Joistick.o \
./src/LedPwm.o \
./src/Timer.o \
./src/_write.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DSTM32F072 -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f0-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


