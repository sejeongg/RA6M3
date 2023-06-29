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
File        : GUI_SetOrientation.h
Purpose     : Private include file for GUI_SetOrientation_xxx
---------------------------END-OF-HEADER------------------------------
*/

#ifndef GUI_SETORIENTATION_H
#define GUI_SETORIENTATION_H

#include "GUI.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
//
// Use unique context identified
//
#define DRIVER_CONTEXT DRIVER_CONTEXT_ORIENTATION

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
/*********************************************************************
*
*       DRIVER_CONTEXT
*/
typedef struct DRIVER_CONTEXT DRIVER_CONTEXT;

struct DRIVER_CONTEXT {
  void (* pfLog2Phys)(DRIVER_CONTEXT * pContext, int x, int y, int * px_phys, int * py_phys);
  U8 * pData;
  int BytesPerPixel;
  int BytesPerLine;
  int Orientation;
  int xSize, ySize;
  int vxSize, vySize;
  int PixelOffset;
  const GUI_ORIENTATION_API * pDrawingAPI;
};

/*********************************************************************
*
*       Private interface
*
**********************************************************************
*/
void GUI__Sort(int * p0, int * p1);

#endif /* GUI_SETORIENTATION_H */

/*************************** End of file ****************************/
