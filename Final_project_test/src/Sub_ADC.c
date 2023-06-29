#include "hal_data.h"
#include "Sub_ADC.h"
#include "Sub_UART.h"
#include "Binary.h"

uint16_t potentiometer_mV = 0, potentiometer_Ra = 0, potentiometer_Rb = 0, potentiometer_Per = 0;
uint16_t termperature_mV=0; int16_t temperature=0;
uint16_t cds_data, cds_bit;

uint8_t monitor_data[6] ;

typedef enum{
    CDS_light = 0,
    CDS_dark = 1,
}CDS_t;

CDS_t brightness;

const float ADC_CONST = (float)(3.3/4096);

void ADC_Send(uint8_t ch, uint8_t data1_num)
{
    monitor_data[0] = 0x02;
    monitor_data[1] = data1_num;
    monitor_data[5] = 0x03;

    switch(ch)
    {
        case 1:
            ADC_Read_and_Convert_Po();
            monitor_data[2] = 0xA9;
            monitor_data[3] = (DATA_LENGTH_9 << 4 ) | DATA_LENGTH_0;
            monitor_data[4] = (DATA_LENGTH_1 << 7) | ( potentiometer_Per & BIT7_MASK);

            break;

        case 2:

            ADC_Read_and_Convert_Th();
            monitor_data[2] = 0xAA;
            monitor_data[3] = (DATA_LENGTH_9 << 4 ) | DATA_LENGTH_1;
            monitor_data[4] = (DATA_LENGTH_0 << 7) | (temperature & BIT7_MASK);

            break;

        case 3:

            ADC_Read_and_Convert_Cd();
            monitor_data[2] = 0xAB;
            monitor_data[3] = (DATA_LENGTH_9 << 4 ) | DATA_LENGTH_1;
            monitor_data[4] = (DATA_LENGTH_1 << 7) | (cds_bit & BIT7_MASK);

            break;
    }
}

void ADC_Control(uint8_t command_adc)
{
    switch(command_adc)
    {
        case COMMAND_002:
            R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
            R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
            break;
    }
}

void ADC_Initial_Setting()
{
    R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
    R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);

}

void Potentiometer_Read()
{
    uint16_t ch0_adc_result;

    R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_0 , &ch0_adc_result);
    potentiometer_mV = (uint16_t)(ch0_adc_result * ADC_CONST * 1000);
    potentiometer_Rb = (uint16_t)(potentiometer_mV * 3.0303);
    potentiometer_Ra = (uint16_t)(10000 - potentiometer_Rb);

    potentiometer_Per = potentiometer_Rb / 100;

}

void Cds_Sensor_Read()
{
    uint16_t ch2_adc_result;

    R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_2 , &ch2_adc_result);
    if(ch2_adc_result >= 400)
    {
        cds_data = ch2_adc_result;
        brightness = CDS_dark;
        cds_bit = 0;
    }
    else
    {
        cds_data = ch2_adc_result;
        brightness = CDS_light;
        cds_bit = 0x7F;
    }
}

void Thermal_Sensor_Read()
{
    uint16_t ch1_adc_result;

    R_ADC_Read(&g_adc1_ctrl, ADC_CHANNEL_1 , &ch1_adc_result);
    termperature_mV = (uint16_t)(ch1_adc_result * ADC_CONST * 1000);

    if(termperature_mV >= 500)
    {
        temperature = (int16_t)((termperature_mV - 500) / 10);
    }
    else
    {
        temperature = (int16_t)((500 - termperature_mV) / 10);
    }
}

void ADC_Read_and_Convert_Po(void)
{
    adc_status_t status;
    R_ADC_ScanStart(&g_adc0_ctrl);

    status.state = ADC_STATE_SCAN_IN_PROGRESS;
    while(ADC_STATE_SCAN_IN_PROGRESS == status.state )
    {
        R_ADC_StatusGet(&g_adc0_ctrl, &status);
    }

    Potentiometer_Read();
}

void ADC_Read_and_Convert_Th(void)
{
    adc_status_t status;
    R_ADC_ScanStart(&g_adc1_ctrl);

    status.state = ADC_STATE_SCAN_IN_PROGRESS;
    while(ADC_STATE_SCAN_IN_PROGRESS == status.state )
    {
        R_ADC_StatusGet(&g_adc1_ctrl, &status);
    }
    Thermal_Sensor_Read();
}

void ADC_Read_and_Convert_Cd(void)
{
    adc_status_t status;
    R_ADC_ScanStart(&g_adc0_ctrl);

    status.state = ADC_STATE_SCAN_IN_PROGRESS;
    while(ADC_STATE_SCAN_IN_PROGRESS == status.state )
    {
        R_ADC_StatusGet(&g_adc0_ctrl, &status);
    }
    Cds_Sensor_Read();

}

