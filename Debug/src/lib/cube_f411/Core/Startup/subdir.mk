################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/lib/cube_f411/Core/Startup/startup_stm32f411ceux.s 

OBJS += \
./src/lib/cube_f411/Core/Startup/startup_stm32f411ceux.o 

S_DEPS += \
./src/lib/cube_f411/Core/Startup/startup_stm32f411ceux.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/cube_f411/Core/Startup/startup_stm32f411ceux.o: ../src/lib/cube_f411/Core/Startup/startup_stm32f411ceux.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"src/lib/cube_f411/Core/Startup/startup_stm32f411ceux.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

