################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/g_DataStructure.c \
../src/g_DeviceDriver.c \
../src/g_Ethernet.c \
../src/g_TSN_TAS.c \
../src/hal_entry.c 

OBJS += \
./src/g_DataStructure.o \
./src/g_DeviceDriver.o \
./src/g_Ethernet.o \
./src/g_TSN_TAS.o \
./src/hal_entry.o 

C_DEPS += \
./src/g_DataStructure.d \
./src/g_DeviceDriver.d \
./src/g_Ethernet.d \
./src/g_TSN_TAS.d \
./src/hal_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\src" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\fsp\inc" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\fsp\inc\api" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\fsp\inc\instances" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra_gen" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra_cfg\fsp_cfg\bsp" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra_cfg\fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '

