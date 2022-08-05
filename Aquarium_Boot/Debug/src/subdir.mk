################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/bsp/ldscript" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/ap/boot" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/ap" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/bsp" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common/core" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common/hw/include/lcd" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/hw" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common/hw/include" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/hw/driver" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

