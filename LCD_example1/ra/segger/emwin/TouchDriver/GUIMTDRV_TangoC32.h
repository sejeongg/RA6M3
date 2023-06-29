/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2021  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V6.22 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only  be used  in accordance  with  a license  and should  not be  re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Software GmbH
Licensed to:              Renesas Electronics America Inc., 1001 Murphy Ranch Road, Milpitas, California 95035, USA
Licensed SEGGER software: emWin
License number:           GUI-00785
License model:            emWin License and Service Agreement, signed May 9th, 2019 
                          and Amendment No. 1, signed June 29, 2021
Licensed platform:        ARM Cortex-M4, -M33 and -M23 based devices of the RA family of the 32-bit Microcontroller Units, designed, marketed and manufactured by LICENSEE only
----------------------------------------------------------------------
File        : GUIMTDRV_TangoC32.h
Purpose     : Interface definition for GUIMTDRV_TangoC32 driver
---------------------------END-OF-HEADER------------------------------
*/

#ifndef GUIMTDRV_TANGOC32_H
#define GUIMTDRV_TANGOC32_H

#include "GUI_Type.h"

#if defined(__cplusplus)
//extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
typedef struct {
  int LayerIndex;
  //
  // Initialization
  //
  void (* pf_I2C_Init)(unsigned char SlaveAddr);
  //
  // Read- and write access
  //
  int (* pf_I2C_Read  )(unsigned char * pData, int Start, int Stop);
  int (* pf_I2C_ReadM )(unsigned char * pData, int NumItems, int Start, int Stop);
  int (* pf_I2C_Write )(unsigned char Data, int Start, int Stop);
  int (* pf_I2C_WriteM)(unsigned char * pData, int NumItems, int Start, int Stop);
  //
  // 7-bit address to be used to address the I2C slave
  //
  U8 SlaveAddr;
} GUIMTDRV_TANGOC32_CONFIG;

/*********************************************************************
*
*       Interface
*
**********************************************************************
*/
int GUIMTDRV_TangoC32_Init(GUIMTDRV_TANGOC32_CONFIG * pConfig);
int GUIMTDRV_TangoC32_Exec(void);

#endif /* GUIMTDRV_TANGOC32_H */

/*************************** End of file ****************************/
