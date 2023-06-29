/*
 * Sub_TIMER.h
 *
 *  Created on: 2023. 2. 6.
 *      Author: tpwjd
 */
#include "hal_data.h"
#include <stdint.h>

#ifndef SUB_TIMER_H_
#define SUB_TIMER_H_


void AGT_Setting();
void Timer_Set(uint8_t command_timer, uint8_t DATA_H, uint8_t DATA_L);
void Timer_Set_ASC(uint8_t command_timer, uint8_t DATA_1, uint8_t DATA_2, uint8_t DATA_3, uint8_t DATA_4);
#endif /* SUB_TIMER_H_ */
