################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_ether_phy/r_ether_phy.c 

OBJS += \
./ra/fsp/src/r_ether_phy/r_ether_phy.o 

C_DEPS += \
./ra/fsp/src/r_ether_phy/r_ether_phy.d 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_ether_phy/%.o: ../ra/fsp/src/r_ether_phy/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\src" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\fsp\inc" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\fsp\inc\api" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\fsp\inc\instances" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra_gen" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra_cfg\fsp_cfg\bsp" -I"C:\Users\Sejeong\ra6m3_ws\RA6M3_IEEE802_1QCI_WithTAS\ra_cfg\fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


