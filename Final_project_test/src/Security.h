/*
 * Security.h
 *
 *  Created on: 2023. 2. 7.
 *      Author: tpwjd
 */
#include "hal_data.h"
#include <stdint.h>

#ifndef SECURITY_H_
#define SECURITY_H_

void Security_Handler(uint8_t GN_Command, uint8_t DLC_Field, uint8_t DataField);
void Security_Handler_ASC(uint8_t GN, uint8_t Command);

#endif /* SECURITY_H_ */
