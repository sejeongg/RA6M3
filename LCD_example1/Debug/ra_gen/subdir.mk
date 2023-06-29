################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/backLight_thread.c \
../ra_gen/common_data.c \
../ra_gen/emWin_thread.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/pin_data.c \
../ra_gen/vector_data.c 

OBJS += \
./ra_gen/backLight_thread.o \
./ra_gen/common_data.o \
./ra_gen/emWin_thread.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/pin_data.o \
./ra_gen/vector_data.o 

C_DEPS += \
./ra_gen/backLight_thread.d \
./ra_gen/common_data.d \
./ra_gen/emWin_thread.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/pin_data.d \
./ra_gen/vector_data.d 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\src" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\fsp\inc" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\fsp\inc\api" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\fsp\inc\instances" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\fsp\src\rm_freertos_port" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\aws\amazon-freertos\freertos_kernel\include" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra_gen" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra_cfg\fsp_cfg\bsp" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra_cfg\fsp_cfg" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra_cfg\aws" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\segger\emwin\WM" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\segger\emwin\Widget" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\segger\emwin\DisplayDriver" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\segger\emwin\Core" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\segger\emwin\AppWizard" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\tes\dave2d\inc" -I"C:\Users\Sejeong\ra6m3_ws\LCD_example1\ra\fsp\src\rm_emwin_port" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


