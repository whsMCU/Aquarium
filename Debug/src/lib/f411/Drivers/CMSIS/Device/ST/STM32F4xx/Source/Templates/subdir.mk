################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c 

OBJS += \
./src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o 

C_DEPS += \
./src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o: ../src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

