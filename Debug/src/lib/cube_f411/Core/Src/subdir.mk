################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/cube_f411/Core/Src/gpio.c \
../src/lib/cube_f411/Core/Src/main.c \
../src/lib/cube_f411/Core/Src/stm32f4xx_hal_msp.c \
../src/lib/cube_f411/Core/Src/stm32f4xx_it.c \
../src/lib/cube_f411/Core/Src/syscalls.c \
../src/lib/cube_f411/Core/Src/sysmem.c \
../src/lib/cube_f411/Core/Src/system_stm32f4xx.c 

OBJS += \
./src/lib/cube_f411/Core/Src/gpio.o \
./src/lib/cube_f411/Core/Src/main.o \
./src/lib/cube_f411/Core/Src/stm32f4xx_hal_msp.o \
./src/lib/cube_f411/Core/Src/stm32f4xx_it.o \
./src/lib/cube_f411/Core/Src/syscalls.o \
./src/lib/cube_f411/Core/Src/sysmem.o \
./src/lib/cube_f411/Core/Src/system_stm32f4xx.o 

C_DEPS += \
./src/lib/cube_f411/Core/Src/gpio.d \
./src/lib/cube_f411/Core/Src/main.d \
./src/lib/cube_f411/Core/Src/stm32f4xx_hal_msp.d \
./src/lib/cube_f411/Core/Src/stm32f4xx_it.d \
./src/lib/cube_f411/Core/Src/syscalls.d \
./src/lib/cube_f411/Core/Src/sysmem.d \
./src/lib/cube_f411/Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/cube_f411/Core/Src/gpio.o: ../src/lib/cube_f411/Core/Src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/cube_f411/Core/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/cube_f411/Core/Src/main.o: ../src/lib/cube_f411/Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/cube_f411/Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/cube_f411/Core/Src/stm32f4xx_hal_msp.o: ../src/lib/cube_f411/Core/Src/stm32f4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/cube_f411/Core/Src/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/cube_f411/Core/Src/stm32f4xx_it.o: ../src/lib/cube_f411/Core/Src/stm32f4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/cube_f411/Core/Src/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/cube_f411/Core/Src/syscalls.o: ../src/lib/cube_f411/Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/cube_f411/Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/cube_f411/Core/Src/sysmem.o: ../src/lib/cube_f411/Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/cube_f411/Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/lib/cube_f411/Core/Src/system_stm32f4xx.o: ../src/lib/cube_f411/Core/Src/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/lib/cube_f411/Core/Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

