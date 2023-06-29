#include "hal_data.h"
#include "Control.h"
#include "Security.h"
#include "Binary.h"
#include "Sub_SERVO_DC.h"
#include "Sub_DAC.h"
#include "Sub_Timer.h"
#include "Sub_FND.h"

uint8_t LED_1 = 0x01;
uint8_t LED_2 = 0x01;

bsp_io_port_pin_t  LEDPORT[2]={
                               BSP_IO_PORT_10_PIN_08,
                               BSP_IO_PORT_10_PIN_09
};

extern uint8_t admin_or_root;
extern uint8_t ASCII_data[11];

void Control_Handler(uint8_t GN_Command, uint8_t DLC_Field, uint8_t DataField)
{
    uint8_t Group_Num = ((GN_Command >> 3) & BIT3_MASK);
    uint8_t Command = (GN_Command & BIT3_MASK);
    uint8_t DLC = ((DLC_Field >> 4) & BIT4_MASK);
    uint8_t Data_H = (DLC_Field & BIT4_MASK);
    uint8_t Data_L = DataField;

    switch(Group_Num)
    {
        case GROUP_NUM_LED:

            switch(Command)
            {
                case COMMAND_001:

                    LED_1 ^= 1;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, LEDPORT[0], LED_1);
                    break;

                case COMMAND_002:

                    LED_2 ^= 1;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, LEDPORT[1], LED_2);
                    break;
            }

        break;

        case GROUP_NUM_FND:
            break;

        case GROUP_NUM_DC_MOTOR:

            if(admin_or_root)DC_Rotaion(Command, Data_L);
            break;

        case GROUP_NUM_SERVO_MOTOR:

            if(admin_or_root)SERVO_Rotation(Command);
            break;

        case GROUP_NUM_DAC:

            DAC_SoundPlay(Command);
            break;

        case GROUP_NUM_TIMER:

            if(admin_or_root)Timer_Set(Command, Data_H, Data_L);
            break;
    }

}

void ASC_Control_Handler()
{

    switch(ASCII_data[3])
    {
        case GROUP_ASC_NUM_LED:

            switch(ASCII_data[4])
            {
                case COMMAND_ASC_001:

                    LED_1 ^= 1;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, LEDPORT[0], LED_1);
                    break;

                case COMMAND_ASC_002:

                    LED_2 ^= 1;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, LEDPORT[1], LED_2);
                    break;
            }
            break;

        case GROUP_ASC_NUM_FND:
            FND_expression();
            break;

        case GROUP_ASC_NUM_DC_MOTOR:
            if(admin_or_root)DC_Rotaion_ASC(ASCII_data[4], ASCII_data[7], ASCII_data[8], ASCII_data[9]);
            break;

        case GROUP_ASC_NUM_SERVO_MOTOR:
            if(admin_or_root)SERVO_Rotation_ASC(ASCII_data[4]);
            break;

        case GROUP_ASC_NUM_DAC:
            DAC_SoundPlay_ASC(ASCII_data[4]);
            break;

        case GROUP_ASC_NUM_TIMER:

            if(admin_or_root)Timer_Set_ASC(ASCII_data[4], ASCII_data[6], ASCII_data[7], ASCII_data[8], ASCII_data[9]);
            break;
    }
}
void LED_Initial_Setting()
{
    R_IOPORT_Open(&g_ioport_ctrl, &g_bsp_pin_cfg);
    R_IOPORT_PinWrite(&g_ioport_ctrl, LEDPORT[0], LED_1);
    R_IOPORT_PinWrite(&g_ioport_ctrl, LEDPORT[1], LED_2);
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, true);
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, true);

}


