################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/driver/button.c \
../src/hw/driver/clcd.c \
../src/hw/driver/cli.c \
../src/hw/driver/ds18b20.c \
../src/hw/driver/fatfs.c \
../src/hw/driver/files.c \
../src/hw/driver/flash.c \
../src/hw/driver/gpio.c \
../src/hw/driver/i2c.c \
../src/hw/driver/lcd.c \
../src/hw/driver/led.c \
../src/hw/driver/onewire.c \
../src/hw/driver/reset.c \
../src/hw/driver/rtc.c \
../src/hw/driver/sd.c \
../src/hw/driver/sonar.c \
../src/hw/driver/spi.c \
../src/hw/driver/tds.c \
../src/hw/driver/telemetry.c \
../src/hw/driver/uart.c \
../src/hw/driver/ui_common.c 

OBJS += \
./src/hw/driver/button.o \
./src/hw/driver/clcd.o \
./src/hw/driver/cli.o \
./src/hw/driver/ds18b20.o \
./src/hw/driver/fatfs.o \
./src/hw/driver/files.o \
./src/hw/driver/flash.o \
./src/hw/driver/gpio.o \
./src/hw/driver/i2c.o \
./src/hw/driver/lcd.o \
./src/hw/driver/led.o \
./src/hw/driver/onewire.o \
./src/hw/driver/reset.o \
./src/hw/driver/rtc.o \
./src/hw/driver/sd.o \
./src/hw/driver/sonar.o \
./src/hw/driver/spi.o \
./src/hw/driver/tds.o \
./src/hw/driver/telemetry.o \
./src/hw/driver/uart.o \
./src/hw/driver/ui_common.o 

C_DEPS += \
./src/hw/driver/button.d \
./src/hw/driver/clcd.d \
./src/hw/driver/cli.d \
./src/hw/driver/ds18b20.d \
./src/hw/driver/fatfs.d \
./src/hw/driver/files.d \
./src/hw/driver/flash.d \
./src/hw/driver/gpio.d \
./src/hw/driver/i2c.d \
./src/hw/driver/lcd.d \
./src/hw/driver/led.d \
./src/hw/driver/onewire.d \
./src/hw/driver/reset.d \
./src/hw/driver/rtc.d \
./src/hw/driver/sd.d \
./src/hw/driver/sonar.d \
./src/hw/driver/spi.d \
./src/hw/driver/tds.d \
./src/hw/driver/telemetry.d \
./src/hw/driver/uart.d \
./src/hw/driver/ui_common.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/driver/%.o src/hw/driver/%.su: ../src/hw/driver/%.c src/hw/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/ap" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/bsp" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common/core" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common/hw/include/lcd" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/common/hw/include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/hangul" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/f411/Drivers/CMSIS/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/lib/FatFs/src" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/fatfs" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/image" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium/src/hw/driver/image/source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-hw-2f-driver

clean-src-2f-hw-2f-driver:
	-$(RM) ./src/hw/driver/button.d ./src/hw/driver/button.o ./src/hw/driver/button.su ./src/hw/driver/clcd.d ./src/hw/driver/clcd.o ./src/hw/driver/clcd.su ./src/hw/driver/cli.d ./src/hw/driver/cli.o ./src/hw/driver/cli.su ./src/hw/driver/ds18b20.d ./src/hw/driver/ds18b20.o ./src/hw/driver/ds18b20.su ./src/hw/driver/fatfs.d ./src/hw/driver/fatfs.o ./src/hw/driver/fatfs.su ./src/hw/driver/files.d ./src/hw/driver/files.o ./src/hw/driver/files.su ./src/hw/driver/flash.d ./src/hw/driver/flash.o ./src/hw/driver/flash.su ./src/hw/driver/gpio.d ./src/hw/driver/gpio.o ./src/hw/driver/gpio.su ./src/hw/driver/i2c.d ./src/hw/driver/i2c.o ./src/hw/driver/i2c.su ./src/hw/driver/lcd.d ./src/hw/driver/lcd.o ./src/hw/driver/lcd.su ./src/hw/driver/led.d ./src/hw/driver/led.o ./src/hw/driver/led.su ./src/hw/driver/onewire.d ./src/hw/driver/onewire.o ./src/hw/driver/onewire.su ./src/hw/driver/reset.d ./src/hw/driver/reset.o ./src/hw/driver/reset.su ./src/hw/driver/rtc.d ./src/hw/driver/rtc.o ./src/hw/driver/rtc.su ./src/hw/driver/sd.d ./src/hw/driver/sd.o ./src/hw/driver/sd.su ./src/hw/driver/sonar.d ./src/hw/driver/sonar.o ./src/hw/driver/sonar.su ./src/hw/driver/spi.d ./src/hw/driver/spi.o ./src/hw/driver/spi.su ./src/hw/driver/tds.d ./src/hw/driver/tds.o ./src/hw/driver/tds.su ./src/hw/driver/telemetry.d ./src/hw/driver/telemetry.o ./src/hw/driver/telemetry.su ./src/hw/driver/uart.d ./src/hw/driver/uart.o ./src/hw/driver/uart.su ./src/hw/driver/ui_common.d ./src/hw/driver/ui_common.o ./src/hw/driver/ui_common.su

.PHONY: clean-src-2f-hw-2f-driver

