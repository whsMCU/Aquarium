################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/FatFs/src/diskio.c \
../src/lib/FatFs/src/ff.c \
../src/lib/FatFs/src/ff_gen_drv.c 

OBJS += \
./src/lib/FatFs/src/diskio.o \
./src/lib/FatFs/src/ff.o \
./src/lib/FatFs/src/ff_gen_drv.o 

C_DEPS += \
./src/lib/FatFs/src/diskio.d \
./src/lib/FatFs/src/ff.d \
./src/lib/FatFs/src/ff_gen_drv.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/FatFs/src/diskio.o: ../src/lib/FatFs/src/diskio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/FatFs/src/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/FatFs/src/ff.o: ../src/lib/FatFs/src/ff.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/FatFs/src/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/FatFs/src/ff_gen_drv.o: ../src/lib/FatFs/src/ff_gen_drv.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/FatFs/src/ff_gen_drv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

