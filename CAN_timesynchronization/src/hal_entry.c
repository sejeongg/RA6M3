#include "hal_data.h"
#include "string.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

uint8_t Rx_data[8];
uint8_t Rx_data_clear[8] = {0,};
uint16_t time_stamp_MB = 0;
uint16_t time_stamp_1 = 0;
uint16_t can_timer;
uint8_t Toggle = 1;
uint8_t LED = 1;
can_frame_t g_can_tx_frame;

void CAN_TSTAMP();

/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{

    can_timer = 0;
    /* TODO: add your own code here */
    R_CAN_Open(&g_can0_ctrl, &g_can0_cfg);

    R_ICU_ExternalIrqOpen(&g_external_irq11_ctrl, &g_external_irq11_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq11_ctrl);

    R_PORT10->PDR_b.PDR8 = 1U;
    R_PORT10->PODR_b.PODR8 = 1U;

    R_PORT4->PDR_b.PDR3 = 1U;
    R_PORT4->PODR_b.PODR3 = 1U;

    R_AGT_Open(&g_timer0_ctrl, &g_timer0_cfg);
    R_AGT_Start(&g_timer0_ctrl);

    while(true);

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


void CAN_TSTAMP()
{
    can_timer = R_CAN1->MB[2].TS_b.TSL;
}

/* Callback function */
void CAN_CALLBACK(can_callback_args_t *p_args)
{
    memcpy(Rx_data, Rx_data_clear, 8);

    /* TODO: add your own code here */
    if(p_args->event == CAN_EVENT_RX_COMPLETE)
    {

        memcpy(Rx_data, p_args->frame.data, 8);

        R_CAN1->MB[2].TS_b.TSH = 0;
        R_CAN1->MB[2].TS_b.TSL = 1;
        time_stamp_MB = R_CAN1->MB[2].TS;
        time_stamp_1 = R_CAN1->TSR;
    }
}

/* Callback function */
void SW_INTERRUPT(external_irq_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);

    /* TODO: add your own code here */
    /* This Code can transmit the message you want */
    uint8_t set_data[] = "CAN_AOK"; // the message you want

    g_can_tx_frame.id = 1;
    g_can_tx_frame.id_mode = CAN_ID_MODE_STANDARD;
    g_can_tx_frame.type = CAN_FRAME_TYPE_DATA;
    g_can_tx_frame.data_length_code = 8;

    memcpy(g_can_tx_frame.data, set_data, 8);

    R_CAN_Write(&g_can0_ctrl, 0, &g_can_tx_frame);
}



/* Callback function */
void R_AGT0_INTERRUPT(timer_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    /* TODO: add your own code here */

    R_PORT10->PODR_b.PODR8 = LED;
    if(LED == 0) LED=1;
    else LED=0;

    //LED ^= 0;

    R_PORT4->PODR_b.PODR3 = Toggle;

    if(Toggle == 0) Toggle=1;
    else Toggle=0;

    //Toggle ^= 0;

}
