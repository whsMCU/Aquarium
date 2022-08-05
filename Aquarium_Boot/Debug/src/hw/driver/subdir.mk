################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/driver/button.c \
../src/hw/driver/cli.c \
../src/hw/driver/cmd.c \
../src/hw/driver/files.c \
../src/hw/driver/flash.c \
../src/hw/driver/led.c \
../src/hw/driver/reset.c \
../src/hw/driver/rtc.c \
../src/hw/driver/uart.c \
../src/hw/driver/ymodem.c 

OBJS += \
./src/hw/driver/button.o \
./src/hw/driver/cli.o \
./src/hw/driver/cmd.o \
./src/hw/driver/files.o \
./src/hw/driver/flash.o \
./src/hw/driver/led.o \
./src/hw/driver/reset.o \
./src/hw/driver/rtc.o \
./src/hw/driver/uart.o \
./src/hw/driver/ymodem.o 

C_DEPS += \
./src/hw/driver/button.d \
./src/hw/driver/cli.d \
./src/hw/driver/cmd.d \
./src/hw/driver/files.d \
./src/hw/driver/flash.d \
./src/hw/driver/led.d \
./src/hw/driver/reset.d \
./src/hw/driver/rtc.d \
./src/hw/driver/uart.d \
./src/hw/driver/ymodem.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/driver/%.o src/hw/driver/%.su: ../src/hw/driver/%.c src/hw/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/bsp/ldscript" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/ap/boot" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/ap" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/bsp" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common/core" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common/hw/include/lcd" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/hw" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/common/hw/include" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/hw/driver" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-hw-2f-driver

clean-src-2f-hw-2f-driver:
	-$(RM) ./src/hw/driver/button.d ./src/hw/driver/button.o ./src/hw/driver/button.su ./src/hw/driver/cli.d ./src/hw/driver/cli.o ./src/hw/driver/cli.su ./src/hw/driver/cmd.d ./src/hw/driver/cmd.o ./src/hw/driver/cmd.su ./src/hw/driver/files.d ./src/hw/driver/files.o ./src/hw/driver/files.su ./src/hw/driver/flash.d ./src/hw/driver/flash.o ./src/hw/driver/flash.su ./src/hw/driver/led.d ./src/hw/driver/led.o ./src/hw/driver/led.su ./src/hw/driver/reset.d ./src/hw/driver/reset.o ./src/hw/driver/reset.su ./src/hw/driver/rtc.d ./src/hw/driver/rtc.o ./src/hw/driver/rtc.su ./src/hw/driver/uart.d ./src/hw/driver/uart.o ./src/hw/driver/uart.su ./src/hw/driver/ymodem.d ./src/hw/driver/ymodem.o ./src/hw/driver/ymodem.su

.PHONY: clean-src-2f-hw-2f-driver

