#include "hal_data.h"
#include "Sub_FND.h"
#include "Binary.h"


uint8_t loop = 1;
uint8_t read = 0;
uint8_t on = 0b0;
uint8_t door = 0b0;

uint8_t soonser = 0;

uint8_t LED1_STATE = 0x01;
uint8_t LED2_STATE = 0x01;
uint8_t LED3_STATE = 0x01;
uint8_t LED4_STATE = 0x01;

uint8_t FND_data = 0;

#define SEGMENT_INDEX         8
#define DIGIT_INDEX           4



static const bsp_io_port_pin_t segment_digit[4] = {
                                      BSP_IO_PORT_03_PIN_05,
                                      BSP_IO_PORT_03_PIN_06,
                                      BSP_IO_PORT_03_PIN_07,
                                      BSP_IO_PORT_03_PIN_08
};
static const bsp_io_port_pin_t segment_led_pin[8] = {
                                           BSP_IO_PORT_06_PIN_14,
                                           BSP_IO_PORT_06_PIN_04,
                                           BSP_IO_PORT_06_PIN_05,
                                           BSP_IO_PORT_06_PIN_06,
                                           BSP_IO_PORT_06_PIN_07,
                                           BSP_IO_PORT_06_PIN_11,
                                           BSP_IO_PORT_06_PIN_12,
                                           BSP_IO_PORT_06_PIN_13
};

uint8_t const number[16] = {0x81, 0xCF, 0x92, 0x86, 0xCC, 0xA4, 0xA0, 0x8D, 0x80, 0X84, 0x88, 0xE0, 0xB1, 0xC2, 0xB0, 0xB8};
extern uint8_t ASCII_data[11];
extern uint8_t count_timer[4];
uint8_t j = 3;

void FND_expression()
{
    switch(ASCII_data[4])
    {
        case COMMAND_ASC_001:
            FND_data = ASCII_data[9];
            count_timer[3] = FND_data & BIT4_MASK;
            break;

        case COMMAND_ASC_002:
            FND_data = ASCII_data[9];
            if(((FND_data & 0xF0) >> 4) == 4 )count_timer[3] =  9 + (FND_data & BIT4_MASK);
            else count_timer[3] = FND_data & BIT4_MASK;
            break;

        case COMMAND_ASC_003:

            for(uint8_t i = 6;  i < 10; i++)
            {
                if(ASCII_data[i] == 0x30)FND_data |= (0x00 << j);
                else FND_data |= (0x01 << j);
                j--;
            }
            count_timer[3] = FND_data & BIT4_MASK;
            break;
    }
    FND_data = 0;
}

void FND_Display_Data(uint8_t digit, uint8_t data)
{
    uint8_t key = 0, idx = 0;

    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);
    FND_Reset();

    /* 7-Segment Digit Selection */
    R_IOPORT_PinWrite(&g_ioport_ctrl, segment_digit[digit], 1);

    /* 7-Segment LED Pin Setting */
    for(idx = 0; idx < SEGMENT_INDEX; idx++)
    {
        key = (uint8_t)(data >> (7 - idx) & 0x01);
        R_IOPORT_PinWrite(&g_ioport_ctrl, segment_led_pin[idx], key);
    }
}

void FND_Print_Data(uint8_t *string)
{
    uint8_t idx = 0;

    if (sizeof(string) != DIGIT_INDEX)
            return;

    for (idx = 0; idx < DIGIT_INDEX; idx++)
         FND_Display_Data(idx, number[string[idx]]);
}

void FND_Reset()
{
    uint8_t idx = 0;

    /* 7-Segment Initialization */
    for (idx = 0; idx < SEGMENT_INDEX; idx++)
    {
        if (idx < DIGIT_INDEX)
            R_IOPORT_PinWrite(&g_ioport_ctrl, segment_digit[idx], BSP_IO_LEVEL_LOW);
        R_IOPORT_PinWrite(&g_ioport_ctrl, segment_led_pin[idx], BSP_IO_LEVEL_HIGH);
    }
}


