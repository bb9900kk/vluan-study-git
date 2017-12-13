################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../MyProtoJava.pb.cc 

CPP_SRCS += \
../nativeLibOne.cpp \
../nativeLibProcessMessage.cpp \
../nativeLibTwo.cpp 

CC_DEPS += \
./MyProtoJava.pb.d 

OBJS += \
./MyProtoJava.pb.o \
./nativeLibOne.o \
./nativeLibProcessMessage.o \
./nativeLibTwo.o 

CPP_DEPS += \
./nativeLibOne.d \
./nativeLibProcessMessage.d \
./nativeLibTwo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/lib/jvm/java-8-oracle/include/ -I/usr/local/include/google/protobuf -I/usr/lib/jvm/java-8-oracle/include/linux -O0 -g3 -Wall -fPIC -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/lib/jvm/java-8-oracle/include/ -I/usr/local/include/google/protobuf -I/usr/lib/jvm/java-8-oracle/include/linux -O0 -g3 -Wall -fPIC -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


