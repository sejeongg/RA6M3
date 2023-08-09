#include "hal_data.h"
#include "UDS.h"
#include "GPT.h"
#include "string.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

void Initial_Setting();


void Serial_Write(char *text);
extern uint8_t VIN[17];
extern uint8_t veryBIG[3750];

//volatile uint8_t UDS_CF_Flag = 0;
volatile UDS_Flag UDS__Flag;

extern volatile uint8_t FC[8];
extern can_frame_t UDS_Tx_CAN_CF;
extern can_frame_t UDS_Tx_CAN_Negative;


can_frame_t UDS_Rx_CAN;
volatile uint16_t can_rx_id = 0;
uint8_t delay = 1;

volatile uint16_t CF_Length; // CF Length : 문자열 고유의 길이
volatile uint16_t ST_min;
volatile uint16_t Block_Size;
volatile uint16_t Block_count;

uint8_t DTC[3] = {0,};

/*           GPT           */
uint32_t SER_Timer_Period = 0x249F00;
int Turn_signal = 0;
/* ----------------------- */

/*        SERVO          */
double temp_calc = 0.0;
uint8_t degree = 0;
uint8_t SERVO_LEN = 0;
/* --------------------- */


/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{

    Initial_Setting();

    Serial_Write("  Hello");
    Serial_Write("  Enter Diagnostic Mode!");
    Serial_Write("  This is RA6M3 Board");

    R_PORT11->PODR_b.PODR0 = 0U;

    /* TODO: add your own code here */



    /********
         * CAN Rx Interrupt does not allow more than two CAN transmissions ;;
         * That's why I put it in the while statement
         */

    while(1){

        if(Block_count >= 1)
        {

            UDS_RESPONSE_CF_Tx(UDS__Flag.Flag, CF_Length);


            if(Block_count == Block_Size)
            {
                Block_count = 0;
                UDS__Flag.Flag = 0;
                Serial_Write("  Pos : Consecutive Frames are Done!!");
            }
            else Block_count++;

        }

    }


#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&g_ioport_ctrl, g_ioport.p_cfg);
    }
}

#if BSP_TZ_SECURE_BUILD
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ();

/* Trustzone Secure Projects require at least one nonsecure callable function in order to build (Remove this if it is not required to build). */
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ()
{

}
#endif

void Callback_IRQ(external_irq_callback_args_t *p_args){

    switch(p_args->channel)
    {
        case 11:
            /// This is DTC Code : P0A08 | 17
            /// DC/DC Converter Status Circuit | Circuit voltage above threshold
            /// Fault Code format follow ISO 15031-6/SAE J2012
            DTC[0] = (0b00 << 6) | (0b00 << 4) | (0xA); // P0A
            DTC[1] = (0x0 << 4) | (0x8); // 08
            DTC[2] = (0x1 << 4) | (0x7); // 17

            break;

        case 12:
            UDS__Flag.PoNeFlag ^= 1;

            break;

        case 13:
            R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN_Negative);

            break;
        case 14:
            if(delay == 1)
            {
                delay = 20;
                R_PORT11->PODR_b.PODR0 = 1U;

            }
            else{

                delay = 1;
                R_PORT11->PODR_b.PODR0 = 0U;
            }


             break;

    }

}

void Initial_Setting()
{
    R_CAN_Open(&g_can0_ctrl, &g_can0_cfg);

    R_ICU_ExternalIrqOpen(&g_external_irq11_ctrl, &g_external_irq11_cfg); //Interrupt START
    R_ICU_ExternalIrqEnable(&g_external_irq11_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq12_ctrl, &g_external_irq12_cfg); //Interrupt START
    R_ICU_ExternalIrqEnable(&g_external_irq12_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq13_ctrl, &g_external_irq13_cfg); //Interrupt START
    R_ICU_ExternalIrqEnable(&g_external_irq13_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq14_ctrl, &g_external_irq14_cfg); //Interrupt START
    R_ICU_ExternalIrqEnable(&g_external_irq14_ctrl);

    SER_GPT_Setting(SER_Timer_Period); //GPT CFG
    R_GPT0->GTCR_b.CST = 1U; // GPT32EH0 Count Start

    R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);

    memset(veryBIG,0xFF,3750);

    LED_SETTING();

    Block_Size = 0;
    Block_count = 0;
}


/* Callback function */
void UART_SERIAL_CALLBACK(uart_callback_args_t *p_args)
{
    /* TODO: add your own code here */
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
void CAN_CALLBACK_A(can_callback_args_t *p_args)
{
    /// CAN MSG Interruptions When One Frame Arrives
    if(p_args->event == CAN_EVENT_RX_COMPLETE)
    {
        /*****
         * Receive CAN ID setting
         */
        can_rx_id = (uint16_t)p_args->frame.id;

        /****
         * Check Receive ID and Frame
         */
        UDS_Rx_CAN.id = (uint16_t)p_args->frame.id;
        memcpy(UDS_Rx_CAN.data,p_args->frame.data, 8);


        if(UDS__Flag.PoNeFlag == Postive) // Positive
        {
            /********
             * FlowControl Receive (From a diagnostic Tester)
             */
            if((p_args->frame.data[0] >> 4) == 0x3){

                //Block_Size = p_args->frame.data[1];
                FC[2] = p_args->frame.data[2]; // ST min : when Consecutive Frame is transmitted, This means Delay time [ms].
                ST_min = FC[2];

                UDS_RESPONSE_FC();

            }

            /********
             * First, Receive UDS protocol
             */
            else{

                UDS(can_rx_id ,p_args->frame.data);
            }

        }
        else if(UDS__Flag.PoNeFlag == Negative)
        {

            uint8_t UDS_Clear[8] = {0,};
            memcpy(UDS_Tx_CAN_Negative.data, UDS_Clear, 8);

            UDS_Tx_CAN_Negative.id = 0x600;
            UDS_Tx_CAN_Negative.id_mode = CAN_ID_MODE_STANDARD;
            UDS_Tx_CAN_Negative.type = CAN_FRAME_TYPE_DATA;
            UDS_Tx_CAN_Negative.data_length_code = 8;

            UDS_Tx_CAN_Negative.data[0] = 0x03;
            UDS_Tx_CAN_Negative.data[1] = NRS;
            UDS_Tx_CAN_Negative.data[2] = UDS_Rx_CAN.data[1];
            UDS_Tx_CAN_Negative.data[3] = 0x10; /// General Reject

            R_CAN_Write(&g_can0_ctrl, 0, &UDS_Tx_CAN_Negative);
            Serial_Write("  !!!!!Negative Frame!!!!!!!");

        }



    }

}

void Serial_Write(char *text)
{
    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
    uint8_t length = strlen(text);
    char Serial_buffer[length + 2];
    char Rear_buffer[2] = {0x0D, 0x0A};

    strcpy(Serial_buffer, text);
    strcat(Serial_buffer, Rear_buffer);

    R_SCI_UART_Write(&g_uart0_ctrl, Serial_buffer, length + 2);

    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

}



