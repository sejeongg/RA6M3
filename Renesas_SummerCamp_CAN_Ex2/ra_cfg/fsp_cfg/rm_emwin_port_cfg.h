/* generated configuration header file - do not edit */
#ifndef RM_EMWIN_PORT_CFG_H_
#define RM_EMWIN_PORT_CFG_H_
#include "common_data.h"

/* Define the available number of bytes available for the GUI */
#define GUI_NUMBYTES     (61440)
#define GUI_HEAPSECTION  ".noinit"

/* Multi layer/display support */
#define GUI_NUM_LAYERS      (16)

/* Multi tasking support */
#define GUI_OS              ((1))
#define GUI_MAXTASK         (5)
#ifndef EMWIN_CFG_RTOS
#define EMWIN_CFG_RTOS     (BSP_CFG_RTOS)
#endif

/* Configuration of available packages */
#define GUI_SUPPORT_TOUCH   ((1))   // Support a touch screen (req. win-manager)
#define GUI_SUPPORT_MOUSE   ((0))   // Support a mouse
#define GUI_SUPPORT_MEMDEV  ((1))  // Memory devices available
#define GUI_SUPPORT_ROTATION   ((1))
#define GUI_WINSUPPORT      ((1))      // Window manager package available
#define GUI_SUPPORT_BIDI    ((0))

/* Debug level setting */
#define GUI_DEBUG_LEVEL     ((GUI_DEBUG_LEVEL_NOCHECK))

/* Wait for Vertical Sync */
#define EMWIN_LCD_VSYNC_WAIT ((1))

/* AA Font rendering */
#define EMWIN_LCD_AA_FONT_CONV_BUFFER_SIZE  (400)

/* JPEG Decode settings */
#if EMWIN_JPEG_USE_HW
 #define EMWIN_JPEG_NOCOPY               ((1))
 #define EMWIN_JPEG_DOUBLE_BUFFER_OUTPUT ((0))
 #define EMWIN_JPEG_TIMEOUT              (50)
 #if !EMWIN_JPEG_NOCOPY
  #define EMWIN_JPEG_NUMBYTES_INBUFFER    (0xFFFFFFFF)
 #else
  #define EMWIN_JPEG_NUMBYTES_INBUFFER    (0xFFFFFFF8U)
 #endif
 #define EMWIN_JPEG_NUMBYTES_OUTBUFFER   (0x4000)
 #define EMWIN_JPEG_BUFFER_SECTION       ".noinit"
#endif
#endif /* RM_EMWIN_PORT_CFG_H_ */
