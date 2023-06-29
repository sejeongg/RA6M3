/*
 * Control.h
 *
 *  Created on: 2023. 2. 3.
 *      Author: tpwjd
 */
#include "hal_data.h"
#include <stdint.h>

#ifndef CONTROL_H_
#define CONTROL_H_


void Control_Handler(uint8_t GN_Command, uint8_t DLC_Field, uint8_t DataField);
void ASC_Control_Handler();

void LED_Initial_Setting();

#endif /* CONTROL_H_ */
