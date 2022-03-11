################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ap/ap.c 

OBJS += \
./src/ap/ap.o 

C_DEPS += \
./src/ap/ap.d 


# Each subdirectory must supply rules for building sources it contributes
src/ap/ap.o: ../src/ap/ap.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/STM32CubeIDE/Aquarium/src" -I"D:/STM32CubeIDE/Aquarium/src/ap" -I"D:/STM32CubeIDE/Aquarium/src/bsp" -I"D:/STM32CubeIDE/Aquarium/src/common" -I"D:/STM32CubeIDE/Aquarium/src/common/core" -I"D:/STM32CubeIDE/Aquarium/src/common/hw/include/lcd" -I"D:/STM32CubeIDE/Aquarium/src/hw" -I"D:/STM32CubeIDE/Aquarium/src/common/hw/include" -I"D:/STM32CubeIDE/Aquarium/src/hw/driver" -I"D:/STM32CubeIDE/Aquarium/src/hw/driver/hangul" -I"D:/STM32CubeIDE/Aquarium/src/lib" -I"D:/STM32CubeIDE/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/STM32CubeIDE/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/Aquarium/src/lib/FatFs/src" -I"D:/STM32CubeIDE/Aquarium/src/hw/driver/fatfs" -I"D:/STM32CubeIDE/Aquarium/src/hw/driver/image" -I"D:/STM32CubeIDE/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/ap/ap.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

