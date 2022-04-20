################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Biblioteca.c \
../src/EjerciciosDeC.c \
../src/TADfiles.c 

OBJS += \
./src/Biblioteca.o \
./src/EjerciciosDeC.o \
./src/TADfiles.o 

C_DEPS += \
./src/Biblioteca.d \
./src/EjerciciosDeC.d \
./src/TADfiles.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


