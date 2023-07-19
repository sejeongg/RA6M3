################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/rm_emwin_port/GUIConf.c \
../ra/fsp/src/rm_emwin_port/GUI_X_OS.c \
../ra/fsp/src/rm_emwin_port/JPEGConf.c \
../ra/fsp/src/rm_emwin_port/LCDConf.c 

OBJS += \
./ra/fsp/src/rm_emwin_port/GUIConf.o \
./ra/fsp/src/rm_emwin_port/GUI_X_OS.o \
./ra/fsp/src/rm_emwin_port/JPEGConf.o \
./ra/fsp/src/rm_emwin_port/LCDConf.o 

C_DEPS += \
./ra/fsp/src/rm_emwin_port/GUIConf.d \
./ra/fsp/src/rm_emwin_port/GUI_X_OS.d \
./ra/fsp/src/rm_emwin_port/JPEGConf.d \
./ra/fsp/src/rm_emwin_port/LCDConf.d 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/rm_emwin_port/%.o: ../ra/fsp/src/rm_emwin_port/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\src" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\fsp\inc" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\fsp\inc\api" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\fsp\inc\instances" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra_gen" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra_cfg\fsp_cfg\bsp" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra_cfg\fsp_cfg" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\fsp\src\rm_freertos_port" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\aws\amazon-freertos\freertos_kernel\include" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\segger\emwin\WM" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\segger\emwin\Widget" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\segger\emwin\DisplayDriver" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\segger\emwin\Core" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\segger\emwin\AppWizard" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\tes\dave2d\inc" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra\fsp\src\rm_emwin_port" -I"C:\Users\Sejeong\ra6m3_ws\Renesas_SummerCamp_CAN_Ex2\ra_cfg\aws" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


