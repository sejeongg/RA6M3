#include <Binary.h>

#include <Sub_UART.h>
#include <Sub_ADC.h>
#include <Sub_DAC.h>
#include <Sub_TIMER.h>
#include <Sub_SERVO_DC.h>
#include <Sub_FND.h>
#include "r_uart_api.h"
#include "r_can_api.h"

#include <Control.h>
#include <Security.h>

#include "hal_data.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER


uint8_t index = 0 , data[6], old_data[6]; // Binary Data
uint8_t asc_index = 0 , ASCII_data[11], old_ASCII_data[11]; // ASCII Data
uint8_t tact_data[6]; // tact Data
uint8_t count_timer[4]={0,0,1,0}; // FND Data

uint8_t adc_ch = 1; // ADC channel : 1(potentiometer) 2(Thermal) 3(CDS)
uint8_t asc_type =0; // asc_type
uint8_t write_protection = 0; // 3 seconds counter

extern uint8_t monitor_data[6]; // ADC Data
extern uint8_t key; // Final key
extern uint16_t key1;
extern uint16_t key2;

uint16_t key_second = 1000; // Timer seconds for 3seconds
can_frame_t bonus; uint32_t b;

void button_setting();

/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{
    /* TODO: add your own code here */
    UART1_Initial_Setting();
    LED_Initial_Setting();
    GPT_Setting();
    CAN_Setting();
    DAC_Initial_Setting();
    ADC_Initial_Setting();
    AGT_Setting();
    FND_Reset();
    button_setting();

    while(1)
    {
        FND_Print_Data(count_timer);
        ADC_Send(adc_ch, 0x5d);
    }

#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif

}

void Message_Clear() // if receive Binary Data, message clear
{
    for(uint8_t i = 0; i <6; i++)data[i] = 0;
    index = 0;

    for(uint8_t i = 0; i <11; i++)ASCII_data[i] =0;
    asc_index =0;
}

void Message_Clear_ASC() // if receive ASCII Data, message clear
{
    for(uint8_t i = 0; i < 11; i++)ASCII_data[i] =0;
    asc_index =0;
}

void Message_STX_check() // Message start
{
    if((data[0] == 0x02) || (ASCII_data[0] == 0x02))Message_Type();
}

void Message_Type() // Select Message type
{
   uint8_t type  = (uint8_t)((data[2] >> 6) & BIT2_MASK);

   if((type == MSG_TYPE_CONTROL) && key == 1) // Binary data (Control)
   {
      Control_Handler(data[2], data[3], data[4]);
   }
   else if((asc_type == MSG_ASC_TYPE_CONTROL) && key == 1) // ASCII data (Control)
   {
       ASC_Control_Handler();
       R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
       asc_type = 0;
   }
   else if(type == MSG_TYPE_SECURITY) // Binary data (Security)
   {
       Security_Handler(data[2], data[3], data[4]);
   }
   else if(asc_type == MSG_ASC_TYPE_SECURITY) // ASCII data (Security)
   {
       Security_Handler_ASC(ASCII_data[3], ASCII_data[4]);
       R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
       asc_type = 0;
   }

}

void button_setting()
{
    R_ICU_ExternalIrqOpen(&g_external_irq11_ctrl, &g_external_irq11_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq11_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq12_ctrl, &g_external_irq12_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq12_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq13_ctrl, &g_external_irq13_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq13_ctrl);
    R_ICU_ExternalIrqOpen(&g_external_irq14_ctrl, &g_external_irq14_cfg);
    R_ICU_ExternalIrqEnable(&g_external_irq14_ctrl);

    old_data[1] = 0x5d;
}

/* Callback function */
void Callback_UART_1(uart_callback_args_t *p_args) // Serial Bus
{
   switch (p_args->event)
   {
       case UART_EVENT_RX_CHAR:

           if((ASCII_data[2] == 0x31) || (ASCII_data[2] == 0x33)) // receive ASCII Data
           {
               ASCII_data[asc_index++] = (uint8_t)p_args->data;
           }
           else // receive Binary Data
           {
               data[index++] = (uint8_t)p_args->data;
               ASCII_data[asc_index++] = (uint8_t)p_args->data;
           }
           break;
   }

   if(index == 6) // analyze Binary Data
   {
       for(uint8_t i = 0; i <6; i++)old_data[i] = data[i];
       Message_STX_check();
       R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
       Message_Clear();
   }

   if(asc_index == 11) // analyze ASCII Data
   {
       for(uint8_t i = 0; i <6; i++)
       {
           data[i] = 0;
           old_data[i] = 0;
           index = 0;
       }
       old_data[1] = 0x5d;
       for(uint8_t i = 0; i <11; i++)old_ASCII_data[i] = ASCII_data[i];

       asc_type  = ASCII_data[2];
       Message_STX_check();
       R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
       Message_Clear_ASC();
   }

}

/* Callback function */
void R_IRQ_Callback(external_irq_callback_args_t *p_args)
{

    switch(p_args -> channel)
    {
        case 11:

            tact_data[0] = 0x02;
            tact_data[1] = 0x5d;
            tact_data[2] = 0x91;
            tact_data[3] = 0xCF;
            tact_data[4] = 0xFF;
            tact_data[5] = 0x03;

            R_SCI_UART_Write(&g_uart1_ctrl, &tact_data[0], 6);
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);

            break;

        case 12:


            bonus.id = 0x41;
            bonus.type = CAN_FRAME_TYPE_DATA;
            bonus.data_length_code = 8;

            bonus.data[0] = 0x4D;
            bonus.data[1] = 0x4C;
            bonus.data[2] = 0x5F;
            bonus.data[3] = 0x46;
            bonus.data[4] = 0x49;
            bonus.data[5] = 0x4E;
            bonus.data[6] = 0x41;
            bonus.data[7] = 0x4C;

            R_CAN_Write(&g_can0_ctrl, 0, &bonus);


            break;
        case 13:

            adc_ch++;

            if(adc_ch == 4)adc_ch = 1;

            if(adc_ch == 2)
            {
                R_ADC_ScanStop(&g_adc0_ctrl);
                R_ADC_Close(&g_adc0_ctrl);

                R_ADC_Open(&g_adc1_ctrl, &g_adc1_cfg);
                R_ADC_ScanCfg(&g_adc1_ctrl, &g_adc1_channel_cfg);
            }
            else
            {
                R_ADC_ScanStop(&g_adc1_ctrl);
                R_ADC_Close(&g_adc1_ctrl);

                R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
                R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
            }

            count_timer[2] = adc_ch;
            break;


        case 14:
            for(uint8_t i = 0; i < 2; i++)count_timer[i] = 0;
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
            break;
    }

}


/* AGT0 : ADC transmit interval 1s~3s */
void R_AGT0_interrupt(timer_callback_args_t *p_args)
{

    R_SCI_UART_Write(&g_uart1_ctrl, &monitor_data[0], 6);
}

/* AGT1 : Timer interval and setting key interval in 3s  */
void R_AGT1_interrupt(timer_callback_args_t *p_args)
{
     uint8_t i = 3000 / key_second;

     if((write_protection == i) && key2 == 0)
     {
         key = 0;
         key1 = 0;
         write_protection = 0;
     }
     else if(key2 == 0xE9D) key = 1;
     else write_protection++;

    if((count_timer[1] == 9) && (count_timer[0] == 9))
    {
        count_timer[1] = 0;
        count_timer[0] = 0;

    }
    else if(count_timer[1] == 9)
    {
        count_timer[0] += 1;
        count_timer[1] = 0;
    }
    else
    {
        count_timer[1] += 1;
    }

}
/* Callback function */
void can_callback(can_callback_args_t *p_args)
{
    /* TODO: add your own code here */
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
