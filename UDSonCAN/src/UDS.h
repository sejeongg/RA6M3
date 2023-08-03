/*
 * UDS.h
 *
 *  Created on: 2023. 8. 1.
 *      Author: Sejeong
 */

#ifndef UDS_H_
#define UDS_H_

typedef enum UDS{

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










void UDS(uint16_t canid, uint8_t * pData);
void UDS_RESPONSE_SF(uint8_t * pData);
void UDS_RESPONSE_FF(uint8_t * pData);
void UDS_RESPONSE_CF();





#endif /* UDS_H_ */
