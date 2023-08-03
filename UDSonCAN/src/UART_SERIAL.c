/*
 * UART_SERIAL.c
 *
 *  Created on: 2023. 6. 14.
 *      Author: Sejeong
 */
#include "hal_data.h"
#include "UART_SERIAL.h"
#include "CAN_SETTING.h"
#include "string.h"

extern uint8_t Rx_SERIAL_DATA[100];

uint8_t CAN_ch = 0;

CAN_Setting_variables CAN;
extern char print[6];
extern char Serial_buffer[100];

void Rx_Serial_Convert()
{


    if(Rx_SERIAL_DATA[0] == '<')
    {

        //CAN_CH
        if(Rx_SERIAL_DATA[4] > 0)
        {
            CAN.CAN_CH = Rx_SERIAL_DATA[4];

            if(CAN.CAN_CH == 'A')
            {
                CAN_ch = 1;
            }
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

void Serial_Write(char *text)
{

    uint8_t length = strlen(text);
    memcpy(Serial_buffer, text, length);

    R_SCI_UART_Write(&g_uart0_ctrl, Serial_buffer, length);
    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

}






