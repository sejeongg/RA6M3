#include "hal_data.h"
#include "Sub_UART.h"
#include "Binary.h"



void UART1_Initial_Setting()
{
    R_SCI_UART_Open(&g_uart1_ctrl, &g_uart1_cfg);
}

void CAN_Setting()
{
    R_CAN_Open(&g_can0_ctrl, &g_can0_cfg);
}


/*
 * Sub_UART.c
 *
 *  Created on: 2023. 2. 3.
 *      Author: tpwjd
 */
