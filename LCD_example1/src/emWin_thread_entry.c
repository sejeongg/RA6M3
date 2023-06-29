#include "emWin_thread.h"
#include "hal_data.h"
#include "C:\Users\Sejeong\AppData\Local\AppWizard\Project\LCD_character\Source\CustomCode\Application.h"
#include "C:\Users\Sejeong\AppData\Local\AppWizard\Project\LCD_character\Source\Generated\Resource.h"
#include "C:\Users\Sejeong\AppData\Local\AppWizard\Project\LCD_character\Source\Generated\ID_SCREEN_00.h"
#include "UART_SERIAL.h"
#include "CAN_SETTING.h"
#include "GPT.h"
#include "FND.h"
#include "LCD.h"

void LED_SETTING();

/*           LCD           */
int positionset(int value);
void LCD_Subject(int y, char *can_sub);
void LCD_Write(int y, char *can_msg);
void LCD_Clear(int y, char *can_clear);
void LCD_Subject_api(int y ,char *can_sub);
void LCD_ID_api(int y ,char *can_id);
void LCD_Write_api(int y ,uint8_t iter ,char *can_msg);
void LCD_Clear_api(int y ,uint8_t iter ,char *can_clear);
char buf;
int cnt = 0;
int posx = 0;
TEXT_Handle create;
/* ----------------------- */

char CAN_SUB[11] = "CAN Message";
char CAN_RxID[7] = "RxID:00";
uint8_t can_len_clear = 0;
uint8_t CAN_Clear_Buffer[8] = {0,};

extern char print[6];

/*           GPT           */
uint32_t SER_Timer_Period = 0x249F00;
/* ----------------------- */

/*          UART           */
uint8_t Rx_SERIAL_DATA[100]={0,};
uint8_t iter = 0;
uint32_t mailbox_number;
bool can_resetmode;
/* ----------------------- */

/*          FND            */
//                      0      1     2     3     4     5     6    7     8      9     I     d
 uint8_t number[12] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90, 0xF9, 0xA1};
 uint8_t print_data[4] = {0xFF, 0xFF, 0xFF, 0xFF};
 uint8_t FND_ID[2] = {0,};
 volatile uint8_t can_rx_id = 0;
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
    R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg); //UART START

   R_ICU_ExternalIrqOpen(&g_external_irq11_ctrl, &g_external_irq11_cfg); //Interrupt START
   R_ICU_ExternalIrqEnable(&g_external_irq11_ctrl);

   R_CAN_Open(&g_can0_ctrl, &g_can0_cfg); //CAN START

   SER_GPT_Setting(SER_Timer_Period); //GPT CFG
   R_GPT0->GTCR_b.CST = 1U; // GPT32EH0 Count Start

   LED_SETTING();
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
    }

    iter++;

    if(Rx_SERIAL_DATA[38] == '>')Rx_Serial_Convert(); // CAN channel, baudrate setting (last msg == '>')

    if(Rx_SERIAL_DATA[2] == 'A' ) //CAN ID and MSG transmission
    {

        switch(p_args->data)
        {
            case'>':
                CAN_MSG_Tx();
                break;
        }
    }
}

/* Callback function */
void CAN_CALLBACK(can_callback_args_t *p_args)
{
    // CAN MSG Interruptions When One Frame Arrives
    if(p_args->event == CAN_EVENT_RX_COMPLETE)
    {
        // Rx CAN ID setting
        can_rx_id = (uint8_t)p_args->frame.id;

        // Rx CAN DATA Processing
        CAN_MSG_Rx(p_args->frame.data);

        // Rx mailbox id settings
        mailbox_number = p_args->mailbox;

        /*           LCD Subject          */
        LCD_Subject_api(-80, CAN_SUB);
        /* ----------------------------- */

        /*           LCD CAN ID          */
        LCD_Clear_api(-40, 7, CAN_RxID);
        CAN_RxID[5] = (can_rx_id / 10) + ASC2D;
        can_rx_id %= 10;
        CAN_RxID[6] = can_rx_id + ASC2D;
        LCD_ID_api(-40, CAN_RxID);
        /* ----------------------------- */



        /*           LCD Clear          */
        uint8_t CAN_Clear[can_len_clear];
        for(int k = 0; k < can_len_clear; k++)
        {
            CAN_Clear[k] = CAN_Clear_Buffer[k];
        }

        LCD_Clear_api(10, can_len_clear,CAN_Clear);
        /* ---------------------------- */


        /*           LCD Write          */
        uint8_t CAN_buffer[p_args->frame.data_length_code];
        can_len_clear = p_args->frame.data_length_code; // for Clearing, set length of can msg.

        for(int k = 0; k < p_args->frame.data_length_code; k++)
        {
            CAN_buffer[k] = p_args->frame.data[k];
            CAN_Clear_Buffer[k] = CAN_buffer[k];
        }

        LCD_Write_api(10, p_args->frame.data_length_code, CAN_buffer);

        /* ---------------------------- */

    }

}



void LCD_Subject_api(int y ,char *can_sub){

    for(int j = 0; j < 11; j++)LCD_Subject(y, can_sub);
    cnt = 0;
    posx = 0;
}

void LCD_ID_api(int y ,char *can_id){

    for(int j = 0; j < 7; j++)LCD_Subject(y, can_id);
    cnt = 0;
    posx = 0;

}

void LCD_Write_api(int y ,uint8_t iter ,char *can_msg){

    for(int l = 0; l < iter; l++)LCD_Write(y, can_msg);
    cnt = 0;
    posx = 0;

}

void LCD_Clear_api(int y ,uint8_t iter ,char *can_clear){

    for(int l = 0; l < iter; l++)LCD_Clear(y, can_clear);
    cnt = 0;
    posx = 0;
}



int positionset(int value)
{
    int result = 0;

    result = 25;
    return result;
}


void LCD_Subject(int y, char *can_sub){

    posx += positionset(cnt);
    buf = can_sub[cnt];

    create = TEXT_Create(60 + posx, y, 480, 272, 0x801, WM_CF_SHOW, &buf, TEXT_CF_LEFT | TEXT_CF_VCENTER);

    TEXT_SetFont(create, GUI_FONT_32B_1);
    TEXT_SetTextColor(create, GUI_WHITE);
    cnt++;

}

void LCD_Write(int y, char *can_msg){

    posx += positionset(cnt);
    buf = can_msg[cnt];

    create = TEXT_Create(60 + posx, y, 480, 272, 0x801, WM_CF_SHOW, &buf, TEXT_CF_LEFT | TEXT_CF_VCENTER);

    TEXT_SetFont(create, GUI_FONT_32B_1);
    TEXT_SetTextColor(create, GUI_WHITE);
    cnt++;
}

void LCD_Clear(int y, char *can_clear){

    posx += positionset(cnt);
    buf = can_clear[cnt];

    create = TEXT_Create(60 + posx, y, 480, 272, 0x801, WM_CF_SHOW, &buf, TEXT_CF_LEFT | TEXT_CF_VCENTER);

    TEXT_SetFont(create, GUI_FONT_32B_1);
    TEXT_SetTextColor(create, GUI_BLACK);
    cnt++;
}
