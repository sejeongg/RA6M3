#include "backLight_thread.h"
/* backLight_thread entry function */
/* pvParameters contains TaskHandle_t */
void backLight_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    R_GPT_Open(&g_timer7_ctrl, &g_timer7_cfg);
    R_GPT_Enable(&g_timer7_ctrl);
    R_GPT_Start(&g_timer7_ctrl);


    while (1)
    {
        vTaskDelay (1);
    }
}
