################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/stm32f0-stdperiph/stm32f0xx_adc.c \
../system/src/stm32f0-stdperiph/stm32f0xx_gpio.c \
../system/src/stm32f0-stdperiph/stm32f0xx_rcc.c \
../system/src/stm32f0-stdperiph/stm32f0xx_tim.c 

C_DEPS += \
./system/src/stm32f0-stdperiph/stm32f0xx_adc.d \
./system/src/stm32f0-stdperiph/stm32f0xx_gpio.d \
./system/src/stm32f0-stdperiph/stm32f0xx_rcc.d \
./system/src/stm32f0-stdperiph/stm32f0xx_tim.d 

OBJS += \
./system/src/stm32f0-stdperiph/stm32f0xx_adc.o \
./system/src/stm32f0-stdperiph/stm32f0xx_gpio.o \
./system/src/stm32f0-stdperiph/stm32f0xx_rcc.o \
./system/src/stm32f0-stdperiph/stm32f0xx_tim.o 


# Each subdirectory must supply rules for building sources it contributes
system/src/stm32f0-stdperiph/%.o: ../system/src/stm32f0-stdperiph/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DSTM32F072 -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f0-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


