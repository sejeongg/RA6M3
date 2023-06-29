#include "hal_data.h"
#include "Sub_SERVO_DC.h"
#include "Binary.h"

//************************************************DC MOTOR SETTING************************************************//

bsp_io_port_pin_t L293_CH0_Enable = BSP_IO_PORT_09_PIN_00;
bsp_io_port_pin_t L293_CH0_Direction = BSP_IO_PORT_09_PIN_01;
uint8_t L293_CH0_Enable_Level = BSP_IO_LEVEL_LOW;
uint8_t L293_CH0_Direction_Level = BSP_IO_LEVEL_LOW;
uint8_t duty_asc_set;

//****************************************************************************************************************//

uint32_t dutyRate = 50;
uint32_t Timer_Period = 0x249F00; // 20[ms] Duty Cycle (50Hz)

//************************************************SERVO MOTOR SETTING************************************************//

const double SERVO_MINIMUM_DUTY = 0.03; // 0.6ms는 0.03 퍼센트
const double SERVO_MAXIMUM_DUTY = 0.12; // 2.4ms는 0.12 퍼센트
const double SERVO_EACH_DEGREE = (SERVO_MAXIMUM_DUTY - SERVO_MINIMUM_DUTY) / 180;
double temp_calc = 0.0;
uint8_t degree = 0;

//****************************************************************************************************************//



void GPT_Setting()
{
    // SERVO MOTOR
    R_MSTP->MSTPCRD_b.MSTPD5 = 0U; // GPT32EH3 Module Stop State Cancel

    R_GPT0->GTCR_b.MD = 0U; // GPT32EH3 Count Mode Setting (Saw-wave PWM mode)
    R_GPT0->GTCR_b.TPCS = 0U;//GPT32EH3 Timer Prescaler Select (PCLKD/1)

    R_GPT0->GTPR = Timer_Period - 1;
    R_GPT0->GTCNT = 0;

    R_GPT0->GTIOR_b.GTIOA = 9U;//General PWM Timer IO Control Register, Pin Function Select
    R_GPT0->GTIOR_b.OAE = 1U;//GPIOCA Output Pin Enable

    R_GPT0->GTCCR[0] = (uint32_t)(Timer_Period * SERVO_MINIMUM_DUTY); // GTCCRA Compare mode 에 쓰이는 레지스터

    // DC MOTOR
    R_GPT3->GTCR_b.MD = 0U; // GPT32EH3 Count Mode Setting (Saw-wave PWM mode)
    R_GPT3->GTCR_b.TPCS = 0U;//GPT32EH3 Timer Prescaler Select (PCLKD/1)

    R_GPT3->GTPR = Timer_Period - 1;
    R_GPT3->GTCNT = 0;

    R_GPT3->GTIOR_b.GTIOA = 9U;//General PWM Timer IO Control Register, Pin Function Select
    R_GPT3->GTIOR_b.OAE = 1U;//GPIOCA Output Pin Enable

    R_GPT3->GTCCR[0] = Timer_Period / 2; // GTCCRA Compare mode 에 쓰이는 레지스터

    R_GPT3->GTCR_b.CST = 1U;
}




void Rotate_Servo(uint8_t degree_set)
{
    temp_calc = (SERVO_MINIMUM_DUTY + SERVO_EACH_DEGREE * (float)degree_set);

    R_GPT0->GTCCR[0] = (uint32_t)(Timer_Period * temp_calc);
}

void SERVO_Rotation(uint8_t command_servo)
{
    R_GPT0->GTCR_b.CST = 1U;

    switch(command_servo)
    {
           case COMMAND_001:
               degree = 0;
               Rotate_Servo(degree);
               break;

           case COMMAND_002:
               degree = 90;
               Rotate_Servo(degree);
               break;

           case COMMAND_003:
               degree = 180;
               Rotate_Servo(degree);
               break;

           case COMMAND_004:

               if(degree != 180)degree += 10;
               Rotate_Servo(degree);
               break;

           case COMMAND_005:

               if(degree != 0)degree -= 10;
               Rotate_Servo(degree);
               break;
   }

}

void SERVO_Rotation_ASC(uint8_t command_servo)
{
    R_GPT0->GTCR_b.CST = 1U;

    switch(command_servo)
    {
           case COMMAND_ASC_001:
               degree = 0;
               Rotate_Servo(degree);
               break;

           case COMMAND_ASC_002:
               degree = 90;
               Rotate_Servo(degree);
               break;

           case COMMAND_ASC_003:
               degree = 180;
               Rotate_Servo(degree);
               break;

           case COMMAND_ASC_004:

               if(degree != 180)degree += 10;
               Rotate_Servo(degree);
               break;

           case COMMAND_ASC_005:

               if(degree != 0)degree -= 10;
               Rotate_Servo(degree);
               break;
   }

}


void DC_Rotaion(uint8_t command_dc, uint8_t duty_set)
{

    switch(command_dc)
    {

        case COMMAND_001:
            L293_CH0_Enable_Level = BSP_IO_LEVEL_HIGH;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Enable, L293_CH0_Enable_Level);
            break;

        case COMMAND_002:
            L293_CH0_Enable_Level = BSP_IO_LEVEL_LOW;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Enable, L293_CH0_Enable_Level);
            break;

        case COMMAND_003:

            if(L293_CH0_Direction_Level == BSP_IO_LEVEL_LOW)R_GPT3->GTCCR[0] = Timer_Period * (uint32_t)duty_set / 100;
            else R_GPT3->GTCCR[0] = Timer_Period * (uint32_t) (100 - duty_set) / 100;
            break;

        case COMMAND_004:

            L293_CH0_Direction_Level = BSP_IO_LEVEL_HIGH;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);
            break;

        case COMMAND_005:

            L293_CH0_Direction_Level = BSP_IO_LEVEL_LOW;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);
            break;

    }
}

void DC_Rotaion_ASC(uint8_t command_dc, uint8_t duty_set1, uint8_t duty_set2, uint8_t duty_set3)
{

    switch(command_dc)
    {

        case COMMAND_ASC_001:
            L293_CH0_Enable_Level = BSP_IO_LEVEL_HIGH;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Enable, L293_CH0_Enable_Level);
            break;

        case COMMAND_ASC_002:
            L293_CH0_Enable_Level = BSP_IO_LEVEL_LOW;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Enable, L293_CH0_Enable_Level);
            break;

        case COMMAND_ASC_003:

            duty_asc_set = (duty_set1 & BIT4_MASK) * 100 + (duty_set2 & BIT4_MASK) * 10 + (duty_set3 & BIT4_MASK);
            if(L293_CH0_Direction_Level == BSP_IO_LEVEL_LOW)R_GPT3->GTCCR[0] = Timer_Period * (uint32_t)duty_asc_set / 100;
            else R_GPT3->GTCCR[0] = Timer_Period * (uint32_t) (100 - duty_asc_set) / 100;
            break;

        case COMMAND_ASC_004:

            L293_CH0_Direction_Level = BSP_IO_LEVEL_HIGH;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);
            break;

        case COMMAND_ASC_005:

            L293_CH0_Direction_Level = BSP_IO_LEVEL_LOW;
            R_IOPORT_PinWrite(&g_ioport_ctrl, L293_CH0_Direction, L293_CH0_Direction_Level);
            break;

    }
}




