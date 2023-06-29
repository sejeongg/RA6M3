#include "hal_data.h"
#include "Sub_DAC.h"
#include "Binary.h"

uint16_t value;
extern unsigned char sound1[192480];
extern unsigned char sound2[190176];

void DAC_Initial_Setting()
{
    R_DAC_Open(&g_dac0_ctrl, &g_dac0_cfg);
    R_DAC_Start(&g_dac0_ctrl);
}


void DAC_SoundPlay(uint8_t command_dac)
{
    switch(command_dac)
    {
        case COMMAND_001:

            sound_write(&sound1[0]);
            break;

        case COMMAND_002:

            sound_write(&sound2[0]);
            break;
    }

}

void DAC_SoundPlay_ASC(uint8_t command_dac)
{
    switch(command_dac)
    {
        case COMMAND_ASC_001:

            sound_write(&sound1[0]);
            break;

        case COMMAND_ASC_002:

            sound_write(&sound2[0]);
            break;
    }

}

void sound_write(unsigned char *pick)
{
    for(uint32_t i = 0; i < 192480; i += 2)
      {
          value = (uint16_t)(pick[i] | (pick[i+1] << 8));
          R_DAC_Write(&g_dac0_ctrl, value);
          R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MICROSECONDS);
      }
}
