################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../motors/Actions.cpp \
../motors/dcMotors.cpp 

OBJS += \
./motors/Actions.o \
./motors/dcMotors.o 

CPP_DEPS += \
./motors/Actions.d \
./motors/dcMotors.d 


# Each subdirectory must supply rules for building sources it contributes
motors/%.o: ../motors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


