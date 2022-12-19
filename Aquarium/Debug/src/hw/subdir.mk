################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/hw.c 

OBJS += \
./src/hw/hw.o 

C_DEPS += \
./src/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/%.o src/hw/%.su: ../src/hw/%.c src/hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/ap" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/bsp" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common/core" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common/hw/include/lcd" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common/hw/include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/hangul" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/FatFs/src" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/fatfs" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/image" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-hw

clean-src-2f-hw:
	-$(RM) ./src/hw/hw.d ./src/hw/hw.o ./src/hw/hw.su

.PHONY: clean-src-2f-hw

