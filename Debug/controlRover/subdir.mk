################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../controlRover/rover_control.cpp \
../controlRover/run.cpp 

OBJS += \
./controlRover/rover_control.o \
./controlRover/run.o 

CPP_DEPS += \
./controlRover/rover_control.d \
./controlRover/run.d 


# Each subdirectory must supply rules for building sources it contributes
controlRover/%.o: ../controlRover/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


