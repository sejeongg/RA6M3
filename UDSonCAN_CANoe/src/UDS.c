/*
 * UDS.c
 *
 *  Created on: 2023. 8. 1.
 *      Author: Sejeong
 */
#include "hal_data.h"
#include "string.h"
#include "r_can.h"
#include "GPT.h"
#include "UDS.h"


extern volatile UDS_Flag UDS__Flag;
uint16_t dataIdentifier = 0x00;
can_frame_t UDS_Tx_CAN;
can_frame_t UDS_Tx_CAN_CF;
can_frame_t UDS_Tx_CAN_Negative;
volatile uint8_t FC[8] = {0,}; // Flow Control Variables

//////// VIN ////////
uint8_t VIN[17] = {0x32, 0x54, 0x33, 0x52, 0x46, 0x52, 0x45,
                  0x56, 0x37, 0x44 , 0x57, 0x31, 0x30, 0x38,
                  0x31, 0x37, 0x37 };

extern volatile uint8_t CF_Length;
extern volatile uint8_t ST_min;
extern volatile uint8_t Block_Size;
extern volatile uint8_t Block_count;

extern uint8_t degree;
extern uint8_t DTC[3];

void UDS(uint16_t canid, uint8_t * pData)
{
    if(canid == 0x700)
    {

        switch(pData[1])
        {

                ////////////////////////////  Data Transmission /////////////////////////////

            case RDBI: // Read Data By Identifier

                /********
                 * Read Data By Identifier : Servo degree
                 * SID : 0x22
                 * Request Parameter : 0x0001
                 */


                dataIdentifier = (pData[2] << Identifier_Shift) | (pData[3]);

                if(dataIdentifier == Servo_id) // SERVO
                {
                    UDS_RESPONSE_SF(pData);

                    UDS_Tx_CAN.data[4] = degree;
                    UDS_Tx_CAN.data[0] += 1;

                    R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);

                    Serial_Write("  Pos : Read Data By Identifier : Servo degree");


                }
                /********
                 * Read Data By Identifier : VIN_number
                 * SID : 0x22
                 * Request Parameter : 0x0002
                 */

                else if(dataIdentifier == VIN_id) // VIN
                {

                    UDS_RESPONSE_FF(pData, sizeof(VIN), VIN);

                    UDS__Flag.Flag = VIN_Flag_On;

                    R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);

                    Serial_Write("  Pos : Read Data By Identifier : VIN Number");


                }

                break;


            case WDBI:  // Write Data By Identifier

                dataIdentifier = (pData[2] << Identifier_Shift) | (pData[3]);

                /********
                 * Write Data By Identifier : Servo_Control
                 * SID : 0x2E
                 * Request Parameter : 0x0001 : degree(0A)
                 * Request Parameter : 0x0002 : degree(AA)
                 */


                if((dataIdentifier == 0x0001) || (dataIdentifier == 0x0002))
                {

                    UDS_RESPONSE_SF(pData);

                    degree = pData[4];
                    Rotate_Servo();

                    R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);

                    Serial_Write("  Pos : Write Data By Identifier : Servo Control");

                }

                break;

                ////////////////////////////////////////////////////////////////////////////

                ////////////////////////////////  DTCs /////////////////////////////////////

            case RDI:  // Read DTC Information

                /********
                 * Read DTC information
                 * SID : 0x19
                 * Sub : 0x0B
                 * Request Parameter : 0x01
                 */


                   dataIdentifier = (pData[2] << Identifier_Shift) | (pData[3]);

                   if(dataIdentifier == First_Fail_DTC)
                   {

                       UDS_RESPONSE_SF(pData);

                       UDS_Tx_CAN.data[4] = DTC[0];
                       UDS_Tx_CAN.data[5] = DTC[1];
                       UDS_Tx_CAN.data[6] = DTC[2];
                       UDS_Tx_CAN.data[0] += 3;

                       R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);

                       Serial_Write("  Pos : Read DTC information");

                   }

                   break;

               /********
                * Clear DTC information
                * SID : 0x14
                * Request Parameter : 0x0001
                */

            case CDI:  // Clear Diagnostic Information

                        //dataIdentifier = (pData[2] << Identifier_Shift) | (pData[3]);


                       UDS_RESPONSE_SF(pData);

                       uint8_t DTC_Clear[3] = {0,};
                       memcpy(DTC, DTC_Clear, 3);

                       R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN);

                       Serial_Write("  Pos : Clear Diagnostic Information");

                   break;
                   ////////////////////////////////////////////////////////////////////////////



        }


    }



}



void UDS_RESPONSE_SF(uint8_t * pData){

    uint8_t UDS_Clear[8] = {0,};
    memcpy(UDS_Tx_CAN.data, UDS_Clear, 8);

    UDS_Tx_CAN.id = 0x600;
    UDS_Tx_CAN.id_mode = CAN_ID_MODE_STANDARD;
    UDS_Tx_CAN.type = CAN_FRAME_TYPE_DATA;
    UDS_Tx_CAN.data_length_code = 8;

    UDS_Tx_CAN.data[0] = 0x03;
    UDS_Tx_CAN.data[1] = pData[1] + 0x40;
    UDS_Tx_CAN.data[2] = pData[2];
    UDS_Tx_CAN.data[3] = pData[3];

}

void UDS_RESPONSE_FF(uint8_t * pData, uint8_t CFData_Size, uint8_t * CFData){

    uint8_t UDS_Clear[8] = {0,};
    memcpy(UDS_Tx_CAN.data, UDS_Clear, 8);

    UDS_Tx_CAN.id = 0x600;
    UDS_Tx_CAN.id_mode = CAN_ID_MODE_STANDARD;
    UDS_Tx_CAN.type = CAN_FRAME_TYPE_DATA;
    UDS_Tx_CAN.data_length_code = 8;

    UDS_Tx_CAN.data[0] = 0x10;
    UDS_Tx_CAN.data[1] = CFData_Size + 0x03;

    CF_Length = CFData_Size;

    UDS_Tx_CAN.data[2] = pData[1] + 0x40;
    UDS_Tx_CAN.data[3] = pData[2];
    UDS_Tx_CAN.data[4] = pData[3];
    UDS_Tx_CAN.data[5] = CFData[0];
    UDS_Tx_CAN.data[6] = CFData[1];
    UDS_Tx_CAN.data[7] = CFData[2];



}


void UDS_RESPONSE_FC(uint16_t length)
{
    Block_Size = 1;

    while(1)
    {
        if(length <= (3 + 7 * Block_Size)) break;
        else Block_Size++;
    }

    uint8_t UDS_Clear[8] = {0,};
    memcpy(UDS_Tx_CAN_CF.data, UDS_Clear, 8);

    UDS_Tx_CAN_CF.id = 0x600;
    UDS_Tx_CAN_CF.id_mode = CAN_ID_MODE_STANDARD;
    UDS_Tx_CAN_CF.type = CAN_FRAME_TYPE_DATA;
    UDS_Tx_CAN_CF.data_length_code = 8;

    UDS_Tx_CAN_CF.data[0] = 0x21;
    Block_count = 1;

    //UDS_RESPONSE_CF_Tx();

}



void UDS_RESPONSE_CF_Tx(volatile uint8_t Flag, uint8_t Size)
{

     for(int k = 1; k < 8; k++ ) UDS_Tx_CAN_CF.data[k] = 0;

     for(int i = 1; i < 8; i++)
     {

         if((Consecutive_Shift + ((Block_count-1) * 8 - (Block_count-1) * 1) + i) == Size)
         {
             break;

         }
         else
         {
             switch(Flag)
             {
                 case VIN_Flag_On:

                     UDS_Tx_CAN_CF.data[i] = VIN[Consecutive_Shift + ((Block_count-1) * 8 - (Block_count-1) * 1) + i];
                     break;
             }


         }

     }

     R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN_CF);
     UDS_Tx_CAN_CF.data[0] += 0x01;
     R_BSP_SoftwareDelay(ST_min, BSP_DELAY_UNITS_MILLISECONDS);


}



