################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Control.c \
../src/Security.c \
../src/Sound_1.c \
../src/Sound_2.c \
../src/Sub_ADC.c \
../src/Sub_DAC.c \
../src/Sub_FND.c \
../src/Sub_SERVO_DC.c \
../src/Sub_TIMER.c \
../src/Sub_UART.c \
../src/hal_entry.c 

OBJS += \
./src/Control.o \
./src/Security.o \
./src/Sound_1.o \
./src/Sound_2.o \
./src/Sub_ADC.o \
./src/Sub_DAC.o \
./src/Sub_FND.o \
./src/Sub_SERVO_DC.o \
./src/Sub_TIMER.o \
./src/Sub_UART.o \
./src/hal_entry.o 

C_DEPS += \
./src/Control.d \
./src/Security.d \
./src/Sound_1.d \
./src/Sound_2.d \
./src/Sub_ADC.d \
./src/Sub_DAC.d \
./src/Sub_FND.d \
./src/Sub_SERVO_DC.d \
./src/Sub_TIMER.d \
./src/Sub_UART.d \
./src/hal_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\src" -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\ra\fsp\inc" -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\ra\fsp\inc\api" -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\ra\fsp\inc\instances" -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\ra_gen" -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\ra_cfg\fsp_cfg\bsp" -I"C:\Users\Sejeong\ra6m3_ws\Final_project_test\ra_cfg\fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


