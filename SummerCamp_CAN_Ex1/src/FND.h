/*
 * FND.h
 *
 *  Created on: 2023. 6. 19.
 *      Author: Sejeong
 */

#ifndef FND_H_
#define FND_H_


#define SEGMENT_INDEX         8
#define DIGIT_INDEX           4

#define PODR_INDEX_HIGH       7
#define PODR_INDEX_LOW        4
#define PODR_DIGIT_MASK       0x01E0
#define PODR_HIGH_MASK        0x7800
#define PODR_LOW_MASK         0x00F0
#define PODR_PIN_MASK         PODR_HIGH_MASK | PODR_LOW_MASK


#endif /* FND_H_ */
