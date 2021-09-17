################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/driver/image/source/fan_32x32x4.c \
../src/hw/driver/image/source/fan_fast_64x64x4.c \
../src/hw/driver/image/source/fan_slow_64x64x4.c 

OBJS += \
./src/hw/driver/image/source/fan_32x32x4.o \
./src/hw/driver/image/source/fan_fast_64x64x4.o \
./src/hw/driver/image/source/fan_slow_64x64x4.o 

C_DEPS += \
./src/hw/driver/image/source/fan_32x32x4.d \
./src/hw/driver/image/source/fan_fast_64x64x4.d \
./src/hw/driver/image/source/fan_slow_64x64x4.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/driver/image/source/fan_32x32x4.o: ../src/hw/driver/image/source/fan_32x32x4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/image/source/fan_32x32x4.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/image/source/fan_fast_64x64x4.o: ../src/hw/driver/image/source/fan_fast_64x64x4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/image/source/fan_fast_64x64x4.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/image/source/fan_slow_64x64x4.o: ../src/hw/driver/image/source/fan_slow_64x64x4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/image/source/fan_slow_64x64x4.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

