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
File        : GUIDRV_NoOpt_1_8.h
Purpose     : Interface definition for non optimized drawing functions
---------------------------END-OF-HEADER------------------------------
*/

#include "GUI.h"

#ifndef GUIDRV_NOOPT_1_8_H
#define GUIDRV_NOOPT_1_8_H

void GUIDRV__NoOpt_XorPixel  (GUI_DEVICE * pDevice, int x, int y);
void GUIDRV__NoOpt_DrawHLine (GUI_DEVICE * pDevice, int x0, int y,  int x1);
void GUIDRV__NoOpt_DrawVLine (GUI_DEVICE * pDevice, int x, int y0,  int y1);
void GUIDRV__NoOpt_FillRect  (GUI_DEVICE * pDevice, int x0, int y0, int x1, int y1);
void GUIDRV__NoOpt_DrawBitmap(GUI_DEVICE * pDevice, int x0, int y0, int xSize, int ySize, int BitsPerPixel, int BytesPerLine, const U8 * pData, int Diff, const LCD_PIXELINDEX * pTrans);

#endif

/*************************** End of file ****************************/
