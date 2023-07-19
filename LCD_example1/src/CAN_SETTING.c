/*
 * CAN_SETTING.c
 *
 *  Created on: 2023. 6. 14.
 *      Author: Sejeong
 */

#include "hal_data.h"
#include "CAN_SETTING.h"
#include "string.h"
#include "UART_SERIAL.h"
#include "r_can.h"
#include "GPT.h"

extern uint8_t Rx_SERIAL_DATA[100];
extern uint8_t iter;

extern unsigned char CAN_Tx_ID[2];
uint8_t reset_flag = 0;
can_frame_t g_can_tx_frame;
can_frame_t conversion_can_tx_frame;

extern uint8_t FND_ID[2];
extern uint8_t number[12];

/*        SERVO          */
double temp_calc = 0.0;
uint8_t degree = 0;
uint8_t SERVO_LEN = 0;
/* --------------------- */

void CAN_Setting(uint16_t acceptance_bit, uint16_t mask_bit)
{
    /* This Code can change the mailbox id */
    R_CAN_Close(&g_can0_ctrl);
    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

    can_extended_cfg_t * p_extend = (can_extended_cfg_t *) g_can0_cfg.p_extend;

    p_extend->p_mailbox[1].mailbox_id = acceptance_bit;
    p_extend->p_mailbox[2].mailbox_id = acceptance_bit;
    p_extend->p_mailbox[3].mailbox_id = acceptance_bit;
    p_extend->p_mailbox_mask[0] = mask_bit;

    R_CAN_Open(&g_can0_ctrl, &g_can0_cfg);
    /*  ---------------------------------- */

    /* This Code can transmit the message you want */
    uint8_t set_data[] = "CAN_AOK"; // the message you want

    g_can_tx_frame.id = 1;
    g_can_tx_frame.id_mode = CAN_ID_MODE_STANDARD;
    g_can_tx_frame.type = CAN_FRAME_TYPE_DATA;
    g_can_tx_frame.data_length_code = 8;

    memcpy(g_can_tx_frame.data, set_data, 8);

    R_CAN_Write(&g_can0_ctrl, 0, &g_can_tx_frame);
    /*  ----------------------------------------- */


    /* Clear the UART MSG */
    int i;

    for(i = 0; i < 100; i++)
    {
        Rx_SERIAL_DATA[i] = 0;
    }
    iter = 0;
    /*  -------------------*/

}

void CAN_MSG_Tx()
{

    // Message protocol for UART to send CAN MSG
    // < C A N I D 1 2 M S G H  E  L  L  O >
    // 0 1 2 3 4 5 ~   8     11

    uint8_t num_M, digit_id, MUL_10;
    uint8_t can_tx_msg_id = 0;
    uint8_t can_tx_msg_id_g = 0;
    uint8_t i = 6;
    digit_id = 0;

    // Purpose : Find where the letter "M" is located---------
    // num_M : see the number of M
    // digit_id : How many digits is  ID
    while(1)
    {
        if(Rx_SERIAL_DATA[i] == 'M')
        {
            num_M = i;
            break;
        }
        else
        {
            i++;
            digit_id++;
        }
    }
    // -----------------------------------------------------


    i = 6;
    uint8_t MUL_10_TIMES = digit_id;


    //Purpose : When CAN MSG TX, set CAN ID------------------
    for(int j = 0; j < digit_id; j++)
    {
        MUL_10 = 1;

        for(int k = 1; k < MUL_10_TIMES; k++){
            MUL_10 *= 10;
        }

        MUL_10_TIMES--;
        can_tx_msg_id += (Rx_SERIAL_DATA[i] - ASC2D) * MUL_10;
        i++;
    }
    // -----------------------------------------------------

    can_tx_msg_id_g = can_tx_msg_id;

    CAN_Tx_ID[0] =  (unsigned char)(can_tx_msg_id_g / 10 + ASC2D);
    can_tx_msg_id_g %= 10;
    CAN_Tx_ID[1] =  (unsigned char)(can_tx_msg_id_g + ASC2D);



    i = num_M + 3;
    uint8_t can_tx_msg_len = 0;

    // Purpose : MSG length extraction, Solution: Find where the letter ">" is located
    // < C A N I D 1 2 M S G H  E  L  L  O >
    // 0 1 2 3 4 5 ~   8     11            16

    while(1)
    {
        if(Rx_SERIAL_DATA[i] == '>')
        {
            i = num_M + 3;
            break; // i = can_tx_msg_len + 1

        }
        else
        {
            i++;
            can_tx_msg_len++;
        }
    }

    conversion_can_tx_frame.id = can_tx_msg_id;
    conversion_can_tx_frame.id_mode = CAN_ID_MODE_STANDARD;
    conversion_can_tx_frame.type = CAN_FRAME_TYPE_DATA;
    conversion_can_tx_frame.data_length_code = can_tx_msg_len;

    // Purpose : Data conversion for CAN TX
    for(int k = 0; k < can_tx_msg_len; k++)
    {
        conversion_can_tx_frame.data[k] = Rx_SERIAL_DATA[i];
        i++;
    }

    R_CAN_Write(&g_can0_ctrl, 0, &conversion_can_tx_frame);


    /* Clear the UART MSG */
    int y;

    for(y = 0; y < 100; y++)
    {
        Rx_SERIAL_DATA[y] = 0;
    }
    iter = 0;
    /* ------------------ */

}

void CAN_MSG_Rx(uint8_t *data)
{
    int s;

    switch(data[0])
    {
        /* LED Control  */
        /* MSG protocol : LD1111, 1(led on) */
        case'L':

            R_PORT10->PODR_b.PODR8 = ~(data[2]-ASC2D);
            R_PORT10->PODR_b.PODR9 = ~(data[3]-ASC2D);
            R_PORT10->PODR_b.PODR10 = ~(data[4]-ASC2D);
            R_PORT11->PODR_b.PODR0 = ~(data[5]-ASC2D);
            break;

        /* SERVO Control  */
        /* MSG protocol : SER(0~180) */
        case 'S':

            s = 3;

            // Purpose : SERVO LEN Extraction
            while(1)
            {
                if(data[s] == 0)
                {
                    break; // i = can_tx_msg_len + 1

                }
                else
                {
                    s++;
                    SERVO_LEN++;
                }
            }

            uint8_t MUL_10;
            uint8_t MUL_10_TIMES = SERVO_LEN;
            s = 3;

            // Purpose : According to digit of SERVO_LEN, make SERVO degree
            for(int j = 0; j < SERVO_LEN; j++)
            {
                MUL_10 = 1;

                for(int k = 1; k < MUL_10_TIMES; k++){
                    MUL_10 *= 10;
                }
                MUL_10_TIMES--;
                degree += (data[s] - ASC2D) * MUL_10;
                s++;
            }

            // Purpose : Rotate Servo function
            Rotate_Servo();
            break;

    }



}

