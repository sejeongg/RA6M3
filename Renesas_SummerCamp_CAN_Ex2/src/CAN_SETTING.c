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



/*           CAN           */
extern uint8_t Rx_SERIAL_DATA[100];
extern uint8_t iter;
extern CAN_Setting_variables CAN;
extern unsigned char CAN_Tx_ID[2];

uint8_t reset_flag = 0;
can_frame_t g_can_tx_frame;
can_frame_t conversion_can_tx_frame;

extern uint8_t CAN_ch;
/* ---------------------- */

/*        Final 과제       */
uint8_t final_ecu_id;
uint8_t final_check = 0;
uint8_t final_tx_right = 0;
uint8_t final_IDSET = 0;

// msg check : IDSET
uint8_t ECU_check[] = {0x49, 0x44, 0x53, 0x45, 0x54};

// ECU 1 : Sungkyun
uint8_t ECU1[] = {0x53,0x75,0x6e,0x67,0x6b,0x79,0x75,0x6e};
// ECU 2 : kwanUniv
uint8_t ECU2[] = {0x6b,0x77,0x61,0x6e,0x55,0x6e,0x69,0x76};
// ECU 3 : Automati
uint8_t ECU3[] = {0x41,0x75,0x74,0x6f,0x6d,0x61,0x74,0x69};
// ECU 4 : oncanedu
uint8_t ECU4[] = {0x6f,0x6e,0x63,0x61,0x6e,0x65,0x64,0x75};
// ECU 5 : cation!!
uint8_t ECU5[] = {0x63,0x61,0x74,0x69,0x6f,0x6e,0x21,0x21};

int array_element_equal(uint8_t a[], uint8_t b[], uint8_t size);

/* ---------------------- */




/*        SERVO          */
double temp_calc = 0.0;
uint8_t degree = 0;
uint8_t SERVO_LEN = 0;
/* --------------------- */

void CAN_Setting(uint16_t acceptance_bit, uint16_t mask_bit)
{
    if(CAN_ch == 1)
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

    }

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

    final_IDSET = array_element_equal(conversion_can_tx_frame.data,ECU_check,5);

    if(final_IDSET == 1)
    {
        R_CAN_Write(&g_can0_ctrl, 0, &conversion_can_tx_frame);
        final_ecu_id = can_tx_msg_id;
        final_IDSET = 0;
    }
    else if(final_ecu_id == 16)
    {
        R_CAN_Write(&g_can0_ctrl, 0, &conversion_can_tx_frame);
    }
    else if(final_ecu_id != 16 && final_tx_right == 1)
    {
        R_CAN_Write(&g_can0_ctrl, 0, &conversion_can_tx_frame);
    }


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

        switch(final_ecu_id)
        {
            case 16:

                if(CAN.CAN_Mask == 0b11111111111 && CAN.CAN_Acceptance == 24)
                {
                    final_check = array_element_equal(data,ECU5,8);

                    if(final_check == 1 && final_ecu_id == 16 )
                    {
                        R_PORT10->PODR_b.PODR8 = 0;
                        R_PORT10->PODR_b.PODR9 = 0;
                        R_PORT10->PODR_b.PODR10 = 0;
                        R_PORT11->PODR_b.PODR0 = 0;
                        final_tx_right = 1;
                    }

                }
                break;
            case 18:

                if(CAN.CAN_Mask == 0b11111111111 && CAN.CAN_Acceptance == 16)
                {
                    final_check = array_element_equal(data,ECU1,8);

                    if(final_check == 1 && final_ecu_id == 18 )
                    {
                        R_PORT10->PODR_b.PODR8 = 0;
                        R_PORT10->PODR_b.PODR9 = 0;
                        R_PORT10->PODR_b.PODR10 = 0;
                        R_PORT11->PODR_b.PODR0 = 0;
                        final_tx_right = 1;
                    }

                }

                break;

            case 20:

                if(CAN.CAN_Mask == 0b11111111111 && CAN.CAN_Acceptance == 18)
                {
                    final_check = array_element_equal(data,ECU2,8);

                    if(final_check == 1 && final_ecu_id == 20 )
                    {
                        R_PORT10->PODR_b.PODR8 = 0;
                        R_PORT10->PODR_b.PODR9 = 0;
                        R_PORT10->PODR_b.PODR10 = 0;
                        R_PORT11->PODR_b.PODR0 = 0;
                        final_tx_right = 1;
                    }
                }
                break;

            case 22:

                if(CAN.CAN_Mask == 0b11111111111 && CAN.CAN_Acceptance == 20)
                {
                    final_check = array_element_equal(data,ECU3,8);

                    if(final_check == 1 && final_ecu_id == 22 )
                    {
                        R_PORT10->PODR_b.PODR8 = 0;
                        R_PORT10->PODR_b.PODR9 = 0;
                        R_PORT10->PODR_b.PODR10 = 0;
                        R_PORT11->PODR_b.PODR0 = 0;
                        final_tx_right = 1;
                    }
                }

                break;

            case 24:

                if(CAN.CAN_Mask == 0b11111111111 && CAN.CAN_Acceptance == 22)
                {
                    final_check = array_element_equal(data,ECU4,8);

                    if(final_check == 1 && final_ecu_id == 24 )
                    {
                        R_PORT10->PODR_b.PODR8 = 0;
                        R_PORT10->PODR_b.PODR9 = 0;
                        R_PORT10->PODR_b.PODR10 = 0;
                        R_PORT11->PODR_b.PODR0 = 0;
                        final_tx_right = 1;
                    }
                }

                break;

        }



}


int array_element_equal(uint8_t a[], uint8_t b[], uint8_t size)
{
    int i, j, s1=0, s2=0;

    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
            if( a[i]==b[j] )
            {     // a에 대한 b의 각 원소가 같으면
                s1++;   // s1을 증가
                break;
            }

    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
            if( b[i]==a[j] )
            {    // b에 대한 a의 각 원소가 같으면
                s2++;    // s2를 증가
                break;
            }

    if (s1==s2 && s1==size)   // s1과 s2의 증가한 값이 같고
        return 1;     // s의 값이 size와 같다면, match
    else
        return 0;
}

