/*
 * GPT.c
 *
 *  Created on: 2023. 6. 22.
 *      Author: Sejeong
 */
#include "hal_data.h"
#include "GPT.h"

extern uint32_t SER_Timer_Period;
extern double temp_calc;
extern uint8_t degree;

const double SERVO_MINIMUM_DUTY = 0.03;
const double SERVO_MAXIMUM_DUTY = 0.12;
const double SERVO_EACH_DEGREE = (SERVO_MAXIMUM_DUTY - SERVO_MINIMUM_DUTY) / 180;


void SER_GPT_Setting(uint32_t period)
{
    R_MSTP->MSTPCRD_b.MSTPD5 = 0U; // GPT32EH0 Module Stop State Cancel

    R_GPT0->GTCR_b.MD = 0U; // GPT32EH0 Count Mode Setting (Saw-wave PWM Mode)
    R_GPT0->GTCR_b.TPCS = 0U; // GPT32EH0 Clock Source Pre-scale Setting (PCLKD/1)

    R_GPT0->GTPR = period - 1; // GPT32EH0 Counting Maximum Cycle Setting
    R_GPT0->GTCNT = 0; // GPT32EH0 Counter Initial Value Setting

    R_GPT0->GTIOR_b.GTIOA = 9U; // Compare Matching Output Control Setting
    R_GPT0->GTIOR_b.OAE = 1U; // GPIOCA Output Pin Enable

    R_GPT0->GTCCR[0] = (uint32_t)(period * SERVO_MINIMUM_DUTY); // GTCCR Initial Setting (Angle = 0[degree])
}

void Rotate_Servo()
{
    temp_calc = (SERVO_MINIMUM_DUTY + SERVO_EACH_DEGREE * (float)degree);

    R_GPT0->GTCCR[0] = (uint32_t)(SER_Timer_Period * temp_calc);
}
