#include "hal_data.h"
#include <stdint.h>

#ifndef SUB_ADC_H_
#define SUB_ADC_H_


void ADC_Control(uint8_t command_adc);
void ADC_Initial_Setting();

void ADC_Send(uint8_t ch, uint8_t data2_num);

void Potentiometer_Read();
void Thermal_Sensor_Read();
void Cds_Sensor_Read();

void ADC_Read_and_Convert_Po(void);
void ADC_Read_and_Convert_Th(void);
void ADC_Read_and_Convert_Cd(void);

#endif /* SUB_ADC_H_ */
