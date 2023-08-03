/*
 * UDS.h
 *
 *  Created on: 2023. 8. 1.
 *      Author: Sejeong
 */

#ifndef UDS_H_
#define UDS_H_

typedef enum UDS{


    NRS = 0x7F, /// Negative UDS Responses

    /////////////////  Diagnostic and Communication Management /////////////////
    DSC = 0x10,  // Diagnostic Session Control
    ER  = 0x11,  // ECU Reset
    SA  = 0x27,  // Security Access
    CR  = 0x28,  // Communication Control
    Authen = 0x29, // Authentication
    TP  = 0x3E,  // Tester Present
    ATP = 0x83,  // Access Timing Parameters
    SDT = 0x84,  // Secured Data Transmission
    CDS = 0x85,  // Control DTC Settings
    ROE = 0x86,  // Response On Event
    LC  = 0x87,   // Link Control
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////  Data Transmission /////////////////////////////
    RDBI = 0x22,  // Read Data By Identifier
    RMBA  = 0x23,  // Read memory By Address
    RSCBI  = 0x24,  // Read Scaling Data By Identifier
    RDBIP  = 0x2A,  // Read Data By Identifier Periodic
    DDDI = 0x2C, // Dynamically Define Data Identifier
    WDBI  = 0x2E,  // Write Data By Identifier
    WMBA = 0x3D,  // Write Memory By Address
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////  DTCs /////////////////////////////////////
    CDI = 0x14,  // Clear Diagnostic Information
    RDI  = 0x19,  // Read DTC Information
    ////////////////////////////////////////////////////////////////////////////


}UDS_SID;

typedef enum UDS_Request_Parameter{

    Identifier_Shift = 8,
    Consecutive_Shift = 2

}UDS_Request;

typedef enum UDS_DataTx_{

    Servo_id = 0x0001,
    VIN_id = 0x0002

}UDS_ID;

typedef struct UDS_CANTP{

    volatile uint8_t Flag; // Consecutive Flag
    volatile uint8_t PoNeFlag; // Positive and Negative Flag, 0 = Positive, 1 = Negative

}UDS_Flag;



typedef enum UDS_CANTP_OnOff{

    ////////////////////////////  Consecutive Frame  ///////////////////////////
    VIN_Flag_On = 1,
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////  Consecutive Frame  ///////////////////////////
    Postive = 0,
    Negative = 1
    ////////////////////////////////////////////////////////////////////////////

}UDS_CF_Switch;

typedef enum UDS_DTC{

    First_Fail_DTC = 0x0B01,


}UDS_DTC_P;



void UDS(uint16_t canid, uint8_t * pData);
void UDS_RESPONSE_SF(uint8_t * pData);
void UDS_RESPONSE_FF(uint8_t * pData, uint8_t CFData_Size, uint8_t * CFData);
void UDS_RESPONSE_FC(uint16_t length);
void UDS_RESPONSE_CF_Tx(volatile uint8_t Flag, uint8_t Size);





#endif /* UDS_H_ */
