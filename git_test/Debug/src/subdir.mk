################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c 

OBJS += \
./src/hal_entry.o 

C_DEPS += \
./src/hal_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\Sejeong\ra6m3_ws\git_test\src" -I"C:\Users\Sejeong\ra6m3_ws\git_test\ra\fsp\inc" -I"C:\Users\Sejeong\ra6m3_ws\git_test\ra\fsp\inc\api" -I"C:\Users\Sejeong\ra6m3_ws\git_test\ra\fsp\inc\instances" -I"C:\Users\Sejeong\ra6m3_ws\git_test\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\Sejeong\ra6m3_ws\git_test\ra_gen" -I"C:\Users\Sejeong\ra6m3_ws\git_test\ra_cfg\fsp_cfg\bsp" -I"C:\Users\Sejeong\ra6m3_ws\git_test\ra_cfg\fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


