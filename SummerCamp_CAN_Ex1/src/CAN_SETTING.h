/*
 * CAN_SETTING.h
 *
 *  Created on: 2023. 6. 14.
 *      Author: Sejeong
 */

#ifndef CAN_SETTING_H_
#define CAN_SETTING_H_


// CAN_Setting Variables
typedef struct{

    uint8_t CAN_CH;
    uint16_t CAN_Baud;
    uint16_t CAN_Mask;
    uint16_t CAN_Acceptance;
    uint8_t CAN_ID;
    uint8_t CAN_MSG[8];

}CAN_Setting_variables;

void CAN_Setting(uint16_t acceptance_bit, uint16_t mask_bit);
void CAN_MSG_Tx();

//Check Expression
//uint8_t CAN_CH_E;
//uint8_t CAN_Baud_E;
//uint8_t CAN_Mask_E[11];
//uint8_t CAN_Acceptance_E[11];
//uint8_t CAN_ID_E;
//uint8_t CAN_MSG_E[8];


#endif /* CAN_SETTING_H_ */
