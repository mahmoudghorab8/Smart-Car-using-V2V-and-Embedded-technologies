################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/PWM.c \
../MCAL/TIMER0.c \
../MCAL/TWI.c \
../MCAL/Timer1_CTC.c \
../MCAL/Timer2.c \
../MCAL/UART_Interrupt.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/PWM.o \
./MCAL/TIMER0.o \
./MCAL/TWI.o \
./MCAL/Timer1_CTC.o \
./MCAL/Timer2.o \
./MCAL/UART_Interrupt.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/PWM.d \
./MCAL/TIMER0.d \
./MCAL/TWI.d \
./MCAL/Timer1_CTC.d \
./MCAL/Timer2.d \
./MCAL/UART_Interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


