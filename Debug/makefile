################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/lib/f411/Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include src/lib/f411/Debug/Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include src/lib/f411/Debug/Core/Startup/subdir.mk
-include src/lib/f411/Debug/Core/Src/subdir.mk
-include src/lib/f411/Debug/subdir.mk
-include src/lib/FatFs/src/option/subdir.mk
-include src/lib/FatFs/src/subdir.mk
-include src/hw/driver/lcd/subdir.mk
-include src/hw/driver/image/source/subdir.mk
-include src/hw/driver/image/subdir.mk
-include src/hw/driver/hangul/subdir.mk
-include src/hw/driver/fatfs/subdir.mk
-include src/hw/driver/subdir.mk
-include src/hw/subdir.mk
-include src/common/core/subdir.mk
-include src/bsp/startup/subdir.mk
-include src/bsp/subdir.mk
-include src/ap/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Aquarium
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Aquarium.elf \

MAP_FILES += \
Aquarium.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Aquarium.list \


# All Target
all: main-build

# Main-build Target
main-build: Aquarium.elf secondary-outputs

# Tool invocations
Aquarium.elf Aquarium.map: $(OBJS) $(USER_OBJS) D:\STM32CubeIDE\Aquarium\src\bsp\ldscript\STM32F411CEUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Aquarium.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\STM32CubeIDE\Aquarium\src\bsp\ldscript\STM32F411CEUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Aquarium.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Aquarium.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Aquarium.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Aquarium.elf Aquarium.list Aquarium.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
