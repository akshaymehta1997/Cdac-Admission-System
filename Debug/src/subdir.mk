################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/admissionsystem.cpp \
../src/capacity.cpp \
../src/center.cpp \
../src/course.cpp \
../src/eligibility.cpp \
../src/main.cpp \
../src/preference.cpp \
../src/student.cpp 

OBJS += \
./src/admissionsystem.o \
./src/capacity.o \
./src/center.o \
./src/course.o \
./src/eligibility.o \
./src/main.o \
./src/preference.o \
./src/student.o 

CPP_DEPS += \
./src/admissionsystem.d \
./src/capacity.d \
./src/center.d \
./src/course.d \
./src/eligibility.d \
./src/main.d \
./src/preference.d \
./src/student.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


