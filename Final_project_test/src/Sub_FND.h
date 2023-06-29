/*
 * Sub_FND.h
 *
 *  Created on: 2023. 2. 6.
 *      Author: tpwjd
 */
#include "hal_data.h"
#include <stdint.h>

#ifndef SUB_FND_H_
#define SUB_FND_H_


void FND_Display_Data(uint8_t digit, uint8_t data);
void FND_Print_Data(uint8_t *string);
void FND_Reset();
void FND_expression();
#endif /* SUB_FND_H_ */
