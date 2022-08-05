################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/bsp.c \
../src/bsp/stm32f4xx_hal_msp.c \
../src/bsp/stm32f4xx_it.c \
../src/bsp/syscalls.c \
../src/bsp/sysmem.c \
../src/bsp/system_stm32f4xx.c 

OBJS += \
./src/bsp/bsp.o \
./src/bsp/stm32f4xx_hal_msp.o \
./src/bsp/stm32f4xx_it.o \
./src/bsp/syscalls.o \
./src/bsp/sysmem.o \
./src/bsp/system_stm32f4xx.o 

C_DEPS += \
./src/bsp/bsp.d \
./src/bsp/stm32f4xx_hal_msp.d \
./src/bsp/stm32f4xx_it.d \
./src/bsp/syscalls.d \
./src/bsp/sysmem.d \
./src/bsp/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/%.o src/bsp/%.su: ../src/bsp/%.c src/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/bsp/ldscript" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/ap/boot" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/ap" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/bsp" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/common" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/common/core" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/common/hw/include/lcd" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/hw" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/common/hw/include" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/hw/driver" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/lib" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium_Boot/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-bsp

clean-src-2f-bsp:
	-$(RM) ./src/bsp/bsp.d ./src/bsp/bsp.o ./src/bsp/bsp.su ./src/bsp/stm32f4xx_hal_msp.d ./src/bsp/stm32f4xx_hal_msp.o ./src/bsp/stm32f4xx_hal_msp.su ./src/bsp/stm32f4xx_it.d ./src/bsp/stm32f4xx_it.o ./src/bsp/stm32f4xx_it.su ./src/bsp/syscalls.d ./src/bsp/syscalls.o ./src/bsp/syscalls.su ./src/bsp/sysmem.d ./src/bsp/sysmem.o ./src/bsp/sysmem.su ./src/bsp/system_stm32f4xx.d ./src/bsp/system_stm32f4xx.o ./src/bsp/system_stm32f4xx.su

.PHONY: clean-src-2f-bsp

