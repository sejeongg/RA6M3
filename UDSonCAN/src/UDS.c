/*
 * UDS.c
 *
 *  Created on: 2023. 8. 1.
 *      Author: Sejeong
 */
#include "hal_data.h"
#include "CAN_SETTING.h"
#include "string.h"
#include "UART_SERIAL.h"
#include "r_can.h"
#include "GPT.h"
#include "UDS.h"

uint8_t j_signal = 0;
uint16_t dataIdentifier = 0x00;
can_frame_t UDS_Tx_CAN;
can_frame_t UDS_Tx_CAN_CF;
can_frame_t UDS_Tx_CAN_CF_A;
uint8_t VIN[16] = {0x0,};
volatile uint8_t FC[8] = {0,}; // Flow Control Variables

extern uint8_t degree;

void UDS(uint16_t canid, uint8_t * pData)
{
    if(canid == 0x70)
    {

        switch(pData[1])
        {
            case RDBI: // Read Data By Identifier

                dataIdentifier = (pData[2] << 4) | (pData[3]);

                if(dataIdentifier == 0x0001) // SERVO
                {
                    UDS_RESPONSE_SF(pData);

                    UDS_Tx_CAN.data[4] = degree;
                    UDS_Tx_CAN.data[0] += 1;

                    R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);

                }
                else if(dataIdentifier == 0x0002) // VIN
                {

                    UDS_RESPONSE_FF(pData);
                    R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);

                }




                return;


            case WDBI:  // Write Data By Identifier

                dataIdentifier = (pData[2] << 4) | (pData[3]);

                if((dataIdentifier == 0x0001) || (dataIdentifier == 0x0002))
                {

                    UDS_RESPONSE_SF(pData);

                    degree = pData[4];
                    Rotate_Servo();

                    R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);


                }

                return;






        }





    }



}



void UDS_RESPONSE_SF(uint8_t * pData){

    uint8_t UDS_Clear[8] = {0,};
    memcpy(UDS_Tx_CAN.data, UDS_Clear, 8);

    UDS_Tx_CAN.id = 0x60;
    UDS_Tx_CAN.id_mode = CAN_ID_MODE_STANDARD;
    UDS_Tx_CAN.type = CAN_FRAME_TYPE_DATA;
    UDS_Tx_CAN.data_length_code = 8;

    UDS_Tx_CAN.data[0] = 0x03;
    UDS_Tx_CAN.data[1] = pData[1] + 0x40;
    UDS_Tx_CAN.data[2] = pData[2];
    UDS_Tx_CAN.data[3] = pData[3];

}

void UDS_RESPONSE_FF(uint8_t * pData){

    uint8_t UDS_Clear[8] = {0,};
    memcpy(UDS_Tx_CAN.data, UDS_Clear, 8);

    UDS_Tx_CAN.id = 0x60;
    UDS_Tx_CAN.id_mode = CAN_ID_MODE_STANDARD;
    UDS_Tx_CAN.type = CAN_FRAME_TYPE_DATA;
    UDS_Tx_CAN.data_length_code = 8;

    UDS_Tx_CAN.data[0] = 0x10;
    UDS_Tx_CAN.data[1] = 0x13;
    UDS_Tx_CAN.data[2] = pData[1] + 0x40;
    UDS_Tx_CAN.data[3] = pData[2];
    UDS_Tx_CAN.data[4] = pData[3];
    UDS_Tx_CAN.data[5] = VIN[0];
    UDS_Tx_CAN.data[6] = VIN[1];
    UDS_Tx_CAN.data[7] = VIN[2];

}

void UDS_RESPONSE_CF()
{

    uint8_t UDS_Clear[8] = {0,};
    memcpy(UDS_Tx_CAN_CF.data, UDS_Clear, 8);

    UDS_Tx_CAN_CF.id = 0x60;
    UDS_Tx_CAN_CF.id_mode = CAN_ID_MODE_STANDARD;
    UDS_Tx_CAN_CF.type = CAN_FRAME_TYPE_DATA;
    UDS_Tx_CAN_CF.data_length_code = 8;

    UDS_Tx_CAN_CF.data[0] = 0x21;

    for(int j = 0; j < 2; j++)
    {
        for(int k = 1; k < 8; k++ ) UDS_Tx_CAN_CF.data[k] = 0;

        for(int i = 1; i < 8; i++)
        {

            if((2 + (j * 8 - j * 1) + i) == 16)
            {
                break;

            }
            else
            {
                UDS_Tx_CAN_CF.data[i] = VIN[2 + (j * 8 - j * 1) + i];
            }

        }


        j_signal = j;

        R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN_CF);


        R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
        UDS_Tx_CAN_CF.data[0] += 0x01;


    }

}



