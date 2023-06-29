/*
 * Sub_SERVO_DC.h
 *
 *  Created on: 2023. 2. 4.
 *      Author: tpwjd
 */
#include "hal_data.h"
#include <stdint.h>

#ifndef SUB_SERVO_DC_H_
#define SUB_SERVO_DC_H_

void Rotate_Servo(uint8_t degree_set);
void GPT_Setting();
void SERVO_Rotation(uint8_t command_servo);
void SERVO_Rotation_ASC(uint8_t command_servo);

void DC_Rotaion(uint8_t command_dc, uint8_t duty_set);
void DC_Rotaion_ASC(uint8_t command_dc, uint8_t duty_set1, uint8_t duty_set2, uint8_t duty_set3);

#endif /* SUB_SERVO_DC_H_ */
