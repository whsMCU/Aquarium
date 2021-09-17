################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/driver/button.c \
../src/hw/driver/clcd.c \
../src/hw/driver/cli.c \
../src/hw/driver/ds18b20.c \
../src/hw/driver/fatfs.c \
../src/hw/driver/files.c \
../src/hw/driver/gpio.c \
../src/hw/driver/i2c.c \
../src/hw/driver/lcd.c \
../src/hw/driver/led.c \
../src/hw/driver/onewire.c \
../src/hw/driver/sd.c \
../src/hw/driver/sonar.c \
../src/hw/driver/spi.c \
../src/hw/driver/tds.c \
../src/hw/driver/uart.c \
../src/hw/driver/ui_common.c 

OBJS += \
./src/hw/driver/button.o \
./src/hw/driver/clcd.o \
./src/hw/driver/cli.o \
./src/hw/driver/ds18b20.o \
./src/hw/driver/fatfs.o \
./src/hw/driver/files.o \
./src/hw/driver/gpio.o \
./src/hw/driver/i2c.o \
./src/hw/driver/lcd.o \
./src/hw/driver/led.o \
./src/hw/driver/onewire.o \
./src/hw/driver/sd.o \
./src/hw/driver/sonar.o \
./src/hw/driver/spi.o \
./src/hw/driver/tds.o \
./src/hw/driver/uart.o \
./src/hw/driver/ui_common.o 

C_DEPS += \
./src/hw/driver/button.d \
./src/hw/driver/clcd.d \
./src/hw/driver/cli.d \
./src/hw/driver/ds18b20.d \
./src/hw/driver/fatfs.d \
./src/hw/driver/files.d \
./src/hw/driver/gpio.d \
./src/hw/driver/i2c.d \
./src/hw/driver/lcd.d \
./src/hw/driver/led.d \
./src/hw/driver/onewire.d \
./src/hw/driver/sd.d \
./src/hw/driver/sonar.d \
./src/hw/driver/spi.d \
./src/hw/driver/tds.d \
./src/hw/driver/uart.d \
./src/hw/driver/ui_common.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/driver/button.o: ../src/hw/driver/button.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/button.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/clcd.o: ../src/hw/driver/clcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/clcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/cli.o: ../src/hw/driver/cli.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/cli.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/ds18b20.o: ../src/hw/driver/ds18b20.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/ds18b20.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/fatfs.o: ../src/hw/driver/fatfs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/fatfs.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/files.o: ../src/hw/driver/files.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/files.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/gpio.o: ../src/hw/driver/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/i2c.o: ../src/hw/driver/i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/i2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/lcd.o: ../src/hw/driver/lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/led.o: ../src/hw/driver/led.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/led.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/onewire.o: ../src/hw/driver/onewire.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/onewire.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/sd.o: ../src/hw/driver/sd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/sonar.o: ../src/hw/driver/sonar.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/sonar.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/spi.o: ../src/hw/driver/spi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/tds.o: ../src/hw/driver/tds.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/tds.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/uart.o: ../src/hw/driver/uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/uart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/hw/driver/ui_common.o: ../src/hw/driver/ui_common.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/3. Project/Aquarium/src" -I"D:/3. Project/Aquarium/src/ap" -I"D:/3. Project/Aquarium/src/bsp" -I"D:/3. Project/Aquarium/src/common" -I"D:/3. Project/Aquarium/src/common/core" -I"D:/3. Project/Aquarium/src/common/hw/include/lcd" -I"D:/3. Project/Aquarium/src/hw" -I"D:/3. Project/Aquarium/src/common/hw/include" -I"D:/3. Project/Aquarium/src/hw/driver" -I"D:/3. Project/Aquarium/src/hw/driver/hangul" -I"D:/3. Project/Aquarium/src/lib" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"D:/3. Project/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/3. Project/Aquarium/src/lib/FatFs/src" -I"D:/3. Project/Aquarium/src/hw/driver/fatfs" -I"D:/3. Project/Aquarium/src/hw/driver/image" -I"D:/3. Project/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/ui_common.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

