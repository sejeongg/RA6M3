/*
 * Binary.h
 *
 *  Created on: 2023. 2. 3.
 *      Author: tpwjd
 */

#ifndef BINARY_H_
#define BINARY_H_


typedef enum{
    BIT1_MASK = 0x01,
    BIT2_MASK = 0x03,
    BIT3_MASK = 0x07,
    BIT4_MASK = 0x0F,
    BIT6_MASK = 0x3F,
    BIT7_MASK = 0x7F,
    BIT8_MASK = 0xFF
}bit_mask_t;


typedef enum{

    MSG_TYPE_CONTROL = 1,
    MSG_TYPE_MONITOR = 2,
    MSG_TYPE_SECURITY = 3,

}msg_type_t;


typedef enum{

    MSG_ASC_TYPE_CONTROL = 0x31,
    MSG_ASC_TYPE_MONITOR = 0x32,
    MSG_ASC_TYPE_SECURITY = 0x33,

}msg_type_asc_t;


typedef enum{
    GROUP_NUM_LED,
    GROUP_NUM_FND,
    GROUP_NUM_TACT ,
    GROUP_NUM_DC_MOTOR,
    GROUP_NUM_SERVO_MOTOR,
    GROUP_NUM_ADC,
    GROUP_NUM_DAC,
    GROUP_NUM_TIMER

}group_number_t;

typedef enum{
    GROUP_ASC_NUM_LED = 0x30,
    GROUP_ASC_NUM_FND = 0x31,

    GROUP_ASC_NUM_DC_MOTOR = 0x33,
    GROUP_ASC_NUM_SERVO_MOTOR = 0x34,

    GROUP_ASC_NUM_DAC = 0x36,
    GROUP_ASC_NUM_TIMER = 0x37

}group_number_asc_t;

typedef enum{
    GROUP_NUM_Write_Protection,
    GROUP_NUM_Previledge

}group_number_s_t;

typedef enum{
    GROUP_ASC_NUM_Write_Protection = 0x30,
    GROUP_ASC_NUM_Previledge = 0x31

}group_number_s_asc_t;


typedef enum{
    COMMAND_000,
    COMMAND_001,
    COMMAND_002,
    COMMAND_003,
    COMMAND_004,
    COMMAND_005,
    COMMAND_006,
    COMMAND_007

}command_t;

typedef enum{

    COMMAND_ASC_000 = 0x30,
    COMMAND_ASC_001 = 0x31,
    COMMAND_ASC_002 = 0x32,
    COMMAND_ASC_003 = 0x33,
    COMMAND_ASC_004 = 0x34,
    COMMAND_ASC_005 = 0x35,
    COMMAND_ASC_006 = 0x36,
    COMMAND_ASC_007 = 0x37

}command_asc_t;

#define DATA_ADC_MASK                0x7F

typedef enum{

    DATA_LENGTH_0,
    DATA_LENGTH_1,
    DATA_LENGTH_2,
    DATA_LENGTH_3,
    DATA_LENGTH_4,
    DATA_LENGTH_5,
    DATA_LENGTH_6,
    DATA_LENGTH_7,
    DATA_LENGTH_8,
    DATA_LENGTH_9,
    DATA_LENGTH_10,
    DATA_LENGTH_11,
    DATA_LENGTH_12

}data_length_t;




#define DATA_DC_CW                   0
#define DATA_DC_CCW                  15
#define DATA_SERVO_PLUS_10           10
#define DATA_SERVO_MINUS_10          10




#endif /* BINARY_H_ */
