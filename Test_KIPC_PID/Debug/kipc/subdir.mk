################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../kipc/CommunicationService.cpp \
../kipc/Interface.cpp \
../kipc/ReadInterface.cpp \
../kipc/WriteInterface.cpp 

OBJS += \
./kipc/CommunicationService.o \
./kipc/Interface.o \
./kipc/ReadInterface.o \
./kipc/WriteInterface.o 

CPP_DEPS += \
./kipc/CommunicationService.d \
./kipc/Interface.d \
./kipc/ReadInterface.d \
./kipc/WriteInterface.d 


# Each subdirectory must supply rules for building sources it contributes
kipc/%.o: ../kipc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -I"/home/test/workspace/Test_KIPC_PID/kipc" -I"/home/test/workspace/Test_KIPC_PID/mainframe" -I"/home/test/workspace/Test_KIPC_PID" -O0 -g3 -Wall -fPIC -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


