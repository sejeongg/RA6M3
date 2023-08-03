#include "emWin_thread.h"
#include "hal_data.h"
#include "C:\Users\Sejeong\ra6m3_ws\UDSonCAN\AppWizard\Source\CustomCode\Application.h"
#include "C:\Users\Sejeong\ra6m3_ws\UDSonCAN\AppWizard\Source\Generated\Resource.h"
#include "C:\Users\Sejeong\ra6m3_ws\UDSonCAN\AppWizard\Source\Generated\ID_SCREEN_00.h"
#include "UART_SERIAL.h"
#include "CAN_SETTING.h"
#include "GPT.h"
#include "FND.h"
#include "GUI.h"
#include "LCD.h"
#include "UDS.h"

void LED_SETTING();

char Serial_buffer[100];
extern can_frame_t conversion_can_tx_frame;
extern volatile uint8_t FC[8];
extern uint8_t VIN[16];
extern can_frame_t UDS_Tx_CAN_CF;

/*           LCD           */
unsigned char CAN_Tx_ID[2] = "00";
uint8_t CAN_RxID[3] = "000";
uint8_t CAN_Buffer[9] = {0,};
uint8_t C_CAN_Buffer[9] = {0,};
uint8_t CAN_Buffer_t[8] = {0,};
uint16_t check_canid = 0;
/* ----------------------- */


/*           GPT           */
uint32_t SER_Timer_Period = 0x249F00;
extern uint8_t degree;
int Turn_signal = 0;
/* ----------------------- */

/*          UART           */
uint8_t Rx_SERIAL_DATA[100]={0,};
uint8_t iter = 0;
uint32_t mailbox_number;
bool can_resetmode;
extern uint8_t CAN_ch;
/* ----------------------- */

/*          FND            */
//                      0      1     2     3     4     5     6    7     8      9     I     d
 uint8_t number[12] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90, 0xF9, 0xA1};
 uint8_t print_data[4] = {0xFF, 0xFF, 0xFF, 0xFF};
 uint8_t FND_ID[2] = {0,};
 volatile uint16_t can_rx_id = 0;
 void R_FND_Print_Data(uint8_t *string);
 void R_FND_Display_Data(uint8_t digit, uint8_t data);
 void FND_Initial_Setting();
 void R_FND_Reset();
 /* ----------------------- */


/* emWin_thread entry function */
/* pvParameters contains TaskHandle_t */
void APPW_X_FS_Init(void);

void APPW_X_FS_Init(void){

}

/* emWin_thread entry function */
/* pvParameters contains TaskHandle_t */


void emWin_thread_entry(void *pvParameters)
{

    FSP_PARAMETER_NOT_USED (pvParameters);

    R_CAN_Open(&g_can0_ctrl, &g_can0_cfg);

    R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg); //UART START

    R_ICU_ExternalIrqOpen(&g_external_irq11_ctrl, &g_external_irq11_cfg); //Interrupt START
    R_ICU_ExternalIrqEnable(&g_external_irq11_ctrl);
    Serial_Write("Interrupt  -> Enabled.");

    SER_GPT_Setting(SER_Timer_Period); //GPT CFG
    R_GPT0->GTCR_b.CST = 1U; // GPT32EH0 Count Start

    Serial_Write("ServoMotor -> Enabled.");

    Serial_Write("I/O_Set    -> Enabled.");
    LED_SETTING();

    memset(VIN, 0xAA, sizeof(VIN));

// FND_Initial_Setting();

    /* TODO: add your own code here */
    MainTask();

    while (1)
    {
        vTaskDelay (1);
    }

}


void Callback_IRQ11(external_irq_callback_args_t *p_args){

    FSP_PARAMETER_NOT_USED(p_args);


    int i;

    for(i = 0; i < 100; i++)
    {
        Rx_SERIAL_DATA[i] = 0;
    }
    iter = 0;
    R_PORT10->PODR_b.PODR8 = 1U;
    R_PORT10->PODR_b.PODR9 = 1U;
    R_PORT10->PODR_b.PODR10 = 1U;
    R_PORT11->PODR_b.PODR0 = 1U;

    UDS_Tx_CAN_CF.data[0] = 0x22;
    R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN_CF);

}

void LED_SETTING()
{
    R_PORT10->PDR_b.PDR8 = 1U;
    R_PORT10->PDR_b.PDR9 = 1U;
    R_PORT10->PDR_b.PDR10 = 1U;
    R_PORT11->PDR_b.PDR0 = 1U;

    R_PORT10->PODR_b.PODR8 = 1U;
    R_PORT10->PODR_b.PODR9 = 1U;
    R_PORT10->PODR_b.PODR10 = 1U;
    R_PORT11->PODR_b.PODR0 = 1U;
}



/* Callback function */
void UART_SERIAL_CALLBACK(uart_callback_args_t *p_args)
{
    // UART 8bit = 1byte (Transmission unit) When received, an interrupt occurs
    if(p_args->event == UART_EVENT_RX_CHAR)
    {
        Rx_SERIAL_DATA[iter] = (uint8_t)p_args->data; // 1바이트씩 다 옮기기
        iter++;
    }


    if(Rx_SERIAL_DATA[38] == '>')
    {
        Rx_Serial_Convert(); // CAN channel, baudrate setting (last msg == '>')
        Serial_Write("CAN_Setting is done!");
    }

    if(Rx_SERIAL_DATA[2] == 'A' ) //CAN ID and MSG transmission
    {

        switch(p_args->data)
        {
            case'>':
                CAN_MSG_Tx();


                /*           LCD Write          */
                for(int x = 0; x < 8; x++) CAN_Buffer_t[x] = 0;
                for(int k = 0; k < conversion_can_tx_frame.data_length_code; k++)
                {
                    CAN_Buffer_t[k] = conversion_can_tx_frame.data[k];
                }
                /* ---------------------------- */

                break;
        }
    }

}

/* Callback function */
void CAN_CALLBACK_A(can_callback_args_t *p_args)
{
    // CAN MSG Interruptions When One Frame Arrives
    if(p_args->event == CAN_EVENT_RX_COMPLETE)
    {
        // Rx CAN ID setting
        can_rx_id = (uint16_t)p_args->frame.id;
        check_canid = can_rx_id;

        if((p_args->frame.data[0] >> 4) == 0x3){

            FC[2] = p_args->frame.data[2];
            UDS_RESPONSE_CF();

        }
        else{

            UDS(can_rx_id ,p_args->frame.data);
        }



        // Rx CAN DATA Processing
        //CAN_MSG_Rx(p_args->frame.data);

        // Rx mailbox id settings
        //mailbox_number = p_args->mailbox;


        /*           LCD CAN ID          */

        CAN_RxID[0] = ((can_rx_id / 100) + ASC2D);
        can_rx_id %= 100;
        CAN_RxID[1] = (can_rx_id/10 + ASC2D);
        can_rx_id %= 10;
        CAN_RxID[2] = (can_rx_id + ASC2D);

        APPW_SetText(ID_SCREEN_00, ID_TEXT_00, CAN_RxID);
        /* ----------------------------- */


        /*           LCD Write          */
        for(int x = 0; x < 9; x++)
        {
            CAN_Buffer[x] = 0;
            C_CAN_Buffer[x] = 0;

        }
        for(int k = 0; k < p_args->frame.data_length_code; k++)
        {
            C_CAN_Buffer[k] = (p_args->frame.data[k]);
            CAN_Buffer[k] = (p_args->frame.data[k] + ASC2D);
        }
        APPW_SetText(ID_SCREEN_00, ID_TEXT_01, CAN_Buffer);
        /* ---------------------------- */

    }

}



