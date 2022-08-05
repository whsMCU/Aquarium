################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ap/boot/boot.c 

OBJS += \
./src/ap/boot/boot.o 

C_DEPS += \
./src/ap/boot/boot.d 


# Each subdirectory must supply rules for building sources it contributes
src/ap/boot/%.o src/ap/boot/%.su: ../src/ap/boot/%.c src/ap/boot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F411xE -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/bsp/ldscript" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/ap/boot" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/ap" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/bsp" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/common" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/common/core" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/common/hw/include/lcd" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/hw" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/common/hw/include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/hw/driver" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/lib" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/CMSIS/Include" -I"C:/Users/jjins/Documents/1. Project/Aquarium/Aquarium_Boot/src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-ap-2f-boot

clean-src-2f-ap-2f-boot:
	-$(RM) ./src/ap/boot/boot.d ./src/ap/boot/boot.o ./src/ap/boot/boot.su

.PHONY: clean-src-2f-ap-2f-boot

