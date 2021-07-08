################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ServiceLayer/subdir.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include ApplicationLayer/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
G7_NewArchi.lss \

FLASH_IMAGE += \
G7_NewArchi.hex \

EEPROM_IMAGE += \
G7_NewArchi.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: G7_NewArchi.elf secondary-outputs

# Tool invocations
G7_NewArchi.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,G7_NewArchi.map -mmcu=atmega32 -o "G7_NewArchi.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

G7_NewArchi.lss: G7_NewArchi.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S G7_NewArchi.elf  >"G7_NewArchi.lss"
	@echo 'Finished building: $@'
	@echo ' '

G7_NewArchi.hex: G7_NewArchi.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex G7_NewArchi.elf  "G7_NewArchi.hex"
	@echo 'Finished building: $@'
	@echo ' '

G7_NewArchi.eep: G7_NewArchi.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex G7_NewArchi.elf  "G7_NewArchi.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: G7_NewArchi.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 G7_NewArchi.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) G7_NewArchi.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
