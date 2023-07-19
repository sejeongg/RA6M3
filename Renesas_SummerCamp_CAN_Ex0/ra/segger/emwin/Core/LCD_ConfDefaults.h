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
File        : LCD_ConfDefaults.h
Purpose     : Valid LCD configuration and defaults
----------------------------------------------------------------------
*/

#ifndef LCD_CONFIG_DEFAULTS_H
#define LCD_CONFIG_DEFAULTS_H

#include "LCDConf.h"            /* Configuration header file */

/**********************************************************
*
*       Configuration defaults
*/
#ifndef   LCD_MIRROR_X
  #define LCD_MIRROR_X 0
#endif
#ifndef   LCD_MIRROR_Y
  #define LCD_MIRROR_Y 0
#endif
#ifndef   LCD_SWAP_XY
  #define LCD_SWAP_XY 0
#endif
#ifndef   LCD_FIRSTCOM0
  #define LCD_FIRSTCOM0 0
#endif
#ifndef   LCD_FIRSTSEG0
  #define LCD_FIRSTSEG0 0
#endif
#ifndef   LCD_SWAP_RB
  #define LCD_SWAP_RB 0
#endif
#ifndef   LCD_DISPLAY_INDEX
  #define LCD_DISPLAY_INDEX 0
#endif
#ifndef   LCD_ENDIAN_BIG
  #define LCD_ENDIAN_BIG 0
#endif
#ifndef   LCD_ALLOW_NON_OPTIMIZED_MODE
  #define LCD_ALLOW_NON_OPTIMIZED_MODE 1
#endif

#endif /* LCD_CONFIG_DEFAULTS_H */

/*************************** End of file ****************************/
