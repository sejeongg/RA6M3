################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_ether_phy/targets/KSZ8091RNB/r_ether_phy_target_ksz8091rnb.c 

OBJS += \
./ra/fsp/src/r_ether_phy/targets/KSZ8091RNB/r_ether_phy_target_ksz8091rnb.o 

C_DEPS += \
./ra/fsp/src/r_ether_phy/targets/KSZ8091RNB/r_ether_phy_target_ksz8091rnb.d 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_ether_phy/targets/KSZ8091RNB/%.o: ../ra/fsp/src/r_ether_phy/targets/KSZ8091RNB/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\Sejeong\ra6m3_ws\PTP\src" -I"C:\Users\Sejeong\ra6m3_ws\PTP\ra\fsp\inc" -I"C:\Users\Sejeong\ra6m3_ws\PTP\ra\fsp\inc\api" -I"C:\Users\Sejeong\ra6m3_ws\PTP\ra\fsp\inc\instances" -I"C:\Users\Sejeong\ra6m3_ws\PTP\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\Sejeong\ra6m3_ws\PTP\ra_gen" -I"C:\Users\Sejeong\ra6m3_ws\PTP\ra_cfg\fsp_cfg\bsp" -I"C:\Users\Sejeong\ra6m3_ws\PTP\ra_cfg\fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


