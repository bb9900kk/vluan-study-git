################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mainframe/frame.cpp \
../mainframe/message.cpp 

OBJS += \
./mainframe/frame.o \
./mainframe/message.o 

CPP_DEPS += \
./mainframe/frame.d \
./mainframe/message.d 


# Each subdirectory must supply rules for building sources it contributes
mainframe/%.o: ../mainframe/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -I"/home/test/workspace/Test_KIPC_PID/kipc" -I"/home/test/workspace/Test_KIPC_PID/mainframe" -I"/home/test/workspace/Test_KIPC_PID" -O0 -g3 -Wall -fPIC -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


