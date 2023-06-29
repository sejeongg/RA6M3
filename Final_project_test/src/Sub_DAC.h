/*
 * Sub_DAC.h
 *
 *  Created on: 2023. 2. 6.
 *      Author: tpwjd
 */
#include "hal_data.h"
#include <stdint.h>

#ifndef SUB_DAC_H_
#define SUB_DAC_H_

void DAC_Initial_Setting();
void DAC_SoundPlay(uint8_t command_dac);
void DAC_SoundPlay_ASC(uint8_t command_dac);
void sound_write(unsigned char *pick);

#endif /* SUB_DAC_H_ */
