#include "hal_data.h"
#include "Security.h"
#include "Binary.h"
#include "Sub_SERVO_DC.h"
#include "Sub_DAC.h"
#include "Sub_ADC.h"


uint16_t key1 = 0;
uint16_t key2 = 0;
uint8_t key = 0;
uint8_t admin_or_root = 0;

typedef enum{
    admin_mode = 0,
    root_mode = 1
}Security_t;

Security_t mode;

extern

void Security_Handler(uint8_t GN_Command, uint8_t DLC_Field, uint8_t DataField)
{
    uint8_t Group_Num = ((GN_Command >> 3) & BIT3_MASK);
    uint8_t Command = (GN_Command & BIT3_MASK);
    uint8_t DLC = ((DLC_Field >> 4) & BIT4_MASK);
    uint8_t Data_H = (DLC_Field & BIT4_MASK);
    uint8_t Data_L = DataField;

    switch(Group_Num)
    {
        case GROUP_NUM_Write_Protection:

            switch(Command)
            {
                case COMMAND_006:
                    key1 = 1;
                    break;

                case COMMAND_007:
                    if(key1){
                        key2 = (Data_H << 8) | Data_L;
                        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, false);
                    }
                    break;
            }
            break;

        case GROUP_NUM_Previledge:

            switch(Command)
            {
                case COMMAND_000:
                    admin_or_root = 0;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, true);
                    mode = admin_or_root;
                    break;

                case COMMAND_007:
                    admin_or_root = 1;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, false);
                    mode = admin_or_root;
                    break;
            }

            break;
    }

}

void Security_Handler_ASC(uint8_t GN, uint8_t Command)
{

    switch(GN)
    {
        case GROUP_ASC_NUM_Write_Protection:

            switch(Command)
            {
                case COMMAND_ASC_006:
                    key1 = 1;
                    break;

                case COMMAND_ASC_007:
                    if(key1)
                    {
                        key2 = 0xE9D;
                        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_10, false);
                    }
                    break;
            }
            break;

        case GROUP_ASC_NUM_Previledge:

            switch(Command)
            {
                case COMMAND_ASC_000:
                    admin_or_root = 0;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, true);
                    mode = admin_or_root;
                    break;

                case COMMAND_ASC_007:
                    admin_or_root = 1;
                    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_11_PIN_00, false);
                    mode = admin_or_root;
                    break;
            }

            break;
    }

}



