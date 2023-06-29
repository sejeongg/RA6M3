/*
 * Sub_TIMER.c
 *
 *  Created on: 2023. 2. 6.
 *      Author: tpwjd
 */

#include "hal_data.h"
#include "Sub_TIMER.h"
#include "Binary.h"

uint32_t adc_monitoring_period_data;
uint32_t count_value;

uint32_t agt_monitoring_period_data;
uint32_t agt_count_value;

extern uint16_t key_second;

void AGT_Setting()
{
    R_AGT_Open(&g_timer1_ctrl, &g_timer1_cfg);

    R_AGT_Open(&g_timer2_ctrl, &g_timer2_cfg);
    R_AGT_Start(&g_timer2_ctrl);

}

void Timer_Set(uint8_t command_timer, uint8_t DATA_H, uint8_t DATA_L)
{
    switch(command_timer)
    {
        case COMMAND_001:

            agt_monitoring_period_data = (uint32_t)((DATA_H << 8) | (DATA_L));

            R_AGT1->AGTMR1 |= 0x41;
            R_AGT1->AGTMR2 |= 0x03;// T = 0.244[ms]

            agt_count_value =  agt_monitoring_period_data / 0.244;
            key_second = agt_monitoring_period_data;

            R_AGT1->AGT = agt_count_value;
            R_AGT_Start(&g_timer2_ctrl);

            break;

        case COMMAND_002:

            adc_monitoring_period_data = (uint32_t)((DATA_H << 8) | (DATA_L));

            R_AGT0->AGTMR1 |= 0x41;
            R_AGT0->AGTMR2 |= 0x03;// T = 0.244[ms]
            count_value =  adc_monitoring_period_data / 0.244;
            R_AGT0->AGT = count_value;

            R_AGT_Start(&g_timer1_ctrl);

            break;
    }
}

void Timer_Set_ASC(uint8_t command_timer, uint8_t DATA_1, uint8_t DATA_2, uint8_t DATA_3, uint8_t DATA_4)
{
    switch(command_timer)
    {
        case COMMAND_ASC_001:

            agt_monitoring_period_data = (uint32_t)((DATA_1 & BIT4_MASK) * 1000 + (DATA_2 & BIT4_MASK) * 100 + (DATA_3 & BIT4_MASK)* 10 + (DATA_4 & BIT4_MASK));

            R_AGT1->AGTMR1 |= 0x41;
            R_AGT1->AGTMR2 |= 0x03;// T = 0.244[ms]

            agt_count_value =  agt_monitoring_period_data / 0.244;
            key_second = agt_monitoring_period_data;

            R_AGT1->AGT = agt_count_value;
            R_AGT_Start(&g_timer2_ctrl);

            break;

        case COMMAND_ASC_002:

            adc_monitoring_period_data = (uint32_t)((DATA_1 & BIT4_MASK) * 1000 + (DATA_2 & BIT4_MASK) * 100 + (DATA_3 & BIT4_MASK)* 10 + (DATA_4 & BIT4_MASK));

            R_AGT0->AGTMR1 |= 0x41;
            R_AGT0->AGTMR2 |= 0x03;// T = 0.244[ms]
            count_value =  adc_monitoring_period_data / 0.244;
            R_AGT0->AGT = count_value;
            R_AGT_Start(&g_timer1_ctrl);

            break;
    }
}
