/*
 * Sub_UART.h
 *
 *  Created on: 2023. 2. 3.
 *      Author: tpwjd
 */

#ifndef SUB_UART_H_
#define SUB_UART_H_


void UART1_Initial_Setting();
void Message_STX_check();
void Message_Type();
void Message_Clear();
void Message_Clear_ASC();
void CAN_Setting();

#endif /* SUB_UART_H_ */
