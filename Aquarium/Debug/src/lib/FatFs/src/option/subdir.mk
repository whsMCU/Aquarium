################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/FatFs/src/option/syscall.c \
../src/lib/FatFs/src/option/unicode.c 

OBJS += \
./src/lib/FatFs/src/option/syscall.o \
./src/lib/FatFs/src/option/unicode.o 

C_DEPS += \
./src/lib/FatFs/src/option/syscall.d \
./src/lib/FatFs/src/option/unicode.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/FatFs/src/option/%.o src/lib/FatFs/src/option/%.su: ../src/lib/FatFs/src/option/%.c src/lib/FatFs/src/option/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/STM32CubeIDE/Aquarium/Aquarium/src" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/ap" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/bsp" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/common" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/common/core" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/common/hw/include/lcd" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/hw" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/common/hw/include" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/hw/driver" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/hw/driver/hangul" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/lib" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/lib/FatFs/src" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/hw/driver/fatfs" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/hw/driver/image" -I"D:/STM32CubeIDE/Aquarium/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-lib-2f-FatFs-2f-src-2f-option

clean-src-2f-lib-2f-FatFs-2f-src-2f-option:
	-$(RM) ./src/lib/FatFs/src/option/syscall.d ./src/lib/FatFs/src/option/syscall.o ./src/lib/FatFs/src/option/syscall.su ./src/lib/FatFs/src/option/unicode.d ./src/lib/FatFs/src/option/unicode.o ./src/lib/FatFs/src/option/unicode.su

.PHONY: clean-src-2f-lib-2f-FatFs-2f-src-2f-option

