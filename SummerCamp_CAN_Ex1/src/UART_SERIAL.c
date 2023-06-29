/*
 * UART_SERIAL.c
 *
 *  Created on: 2023. 6. 14.
 *      Author: Sejeong
 */
#include "hal_data.h"
#include "UART_SERIAL.h"
#include "CAN_SETTING.h"

extern uint8_t Rx_SERIAL_DATA[100];

CAN_Setting_variables CAN;

void Rx_Serial_Convert()
{


    if(Rx_SERIAL_DATA[0] == '<')
    {

        //CAN_CH
        if(Rx_SERIAL_DATA[4] > 0)
        {
            CAN.CAN_CH = Rx_SERIAL_DATA[4];
        }

        //CAN_Baudrate
        if(Rx_SERIAL_DATA[9] > 0)
        {
            CAN.CAN_Baud = ((Rx_SERIAL_DATA[7]- ASC2D ) * 100) + ((Rx_SERIAL_DATA[8]-ASC2D) * 10) + ((Rx_SERIAL_DATA[9]-ASC2D));
        }

        //CAN_MASK
        if(Rx_SERIAL_DATA[23] > 0)
        {
            int j=10;

            for(int i = 13; i <= 23; i ++)
            {
                CAN.CAN_Mask |= (uint16_t)((Rx_SERIAL_DATA[i] - ASC2D) << j);
                j--;
            }

        }

        //CAN_Acceptance Filter
        if(Rx_SERIAL_DATA[37] > 0)
        {
            int k=10;

            for(int i = 27; i <= 37; i ++)
            {
                CAN.CAN_Acceptance |= (uint16_t)((Rx_SERIAL_DATA[i] - ASC2D) << k);
                k--;
            }

        }

    }

    CAN_Setting(CAN.CAN_Acceptance, CAN.CAN_Mask);
}







