/* generated common header file - do not edit */
#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "r_jpeg.h"
#include "dave_driver.h"
#include "r_glcdc.h"
#include "r_display_api.h"
#include "r_ioport.h"
#include "bsp_pin_cfg.h"
FSP_HEADER
extern const jpeg_instance_t g_jpeg0;

/** Access the JPEG instance using these structures when calling API functions directly (::p_api is not used). */
extern jpeg_instance_ctrl_t g_jpeg0_ctrl;
extern const jpeg_cfg_t g_jpeg0_cfg;

#if JPEG_CFG_DECODE_ENABLE
             #ifndef _JPEGDecodeCallback
            void _JPEGDecodeCallback(jpeg_callback_args_t * p_args);
             #endif
            #endif

#if JPEG_CFG_ENCODE_ENABLE
             #ifndef NULL
            void NULL(jpeg_callback_args_t * p_args);
             #endif
            #endif
#if DRW_CFG_CUSTOM_MALLOC
            void * d1_malloc(size_t size);
            void   d1_free(void * ptr);
            #endif
#define GLCDC_CFG_LAYER_1_ENABLE (true)
#define GLCDC_CFG_LAYER_2_ENABLE (false)

#define GLCDC_CFG_CLUT_ENABLE (false)

#define GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R       (false)
#define GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G       (false)
#define GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B       (false)

/* Display on GLCDC Instance. */
extern const display_instance_t g_display0;
extern display_runtime_cfg_t g_display0_runtime_cfg_fg;
extern display_runtime_cfg_t g_display0_runtime_cfg_bg;

/** Access the GLCDC instance using these structures when calling API functions directly (::p_api is not used). */
extern glcdc_instance_ctrl_t g_display0_ctrl;
extern const display_cfg_t g_display0_cfg;

#if ((GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B) && GLCDC_CFG_COLOR_CORRECTION_ENABLE && !(false))
            extern display_gamma_correction_t g_display0_gamma_cfg;
            #endif

#if GLCDC_CFG_CLUT_ENABLE
            extern display_clut_cfg_t g_display0_clut_cfg_glcdc;
            #endif

#ifndef _DisplayVsyncCallback
void _DisplayVsyncCallback(display_callback_args_t *p_args);
#endif

#define DISPLAY_IN_FORMAT_16BITS_RGB565_0
#if defined (DISPLAY_IN_FORMAT_32BITS_RGB888_0) || defined (DISPLAY_IN_FORMAT_32BITS_ARGB8888_0)
            #define DISPLAY_BITS_PER_PIXEL_INPUT0 (32)
            #elif defined (DISPLAY_IN_FORMAT_16BITS_RGB565_0) || defined (DISPLAY_IN_FORMAT_16BITS_ARGB1555_0) || defined (DISPLAY_IN_FORMAT_16BITS_ARGB4444_0)
#define DISPLAY_BITS_PER_PIXEL_INPUT0 (16)
#elif defined (DISPLAY_IN_FORMAT_CLUT8_0)
            #define DISPLAY_BITS_PER_PIXEL_INPUT0 (8)
            #elif defined (DISPLAY_IN_FORMAT_CLUT4_0)
            #define DISPLAY_BITS_PER_PIXEL_INPUT0 (4)
            #else
            #define DISPLAY_BITS_PER_PIXEL_INPUT0 (1)
            #endif
#define DISPLAY_HSIZE_INPUT0                 (480)
#define DISPLAY_VSIZE_INPUT0                 (272)
#define DISPLAY_BUFFER_STRIDE_BYTES_INPUT0   (((DISPLAY_HSIZE_INPUT0 * DISPLAY_BITS_PER_PIXEL_INPUT0 + 0x1FF) >> 9) << 6)
#define DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0  ((DISPLAY_BUFFER_STRIDE_BYTES_INPUT0 * 8) / DISPLAY_BITS_PER_PIXEL_INPUT0)
#if GLCDC_CFG_LAYER_1_ENABLE
            extern uint8_t fb_background[2][DISPLAY_BUFFER_STRIDE_BYTES_INPUT0 * DISPLAY_VSIZE_INPUT0];
            #endif

#define DISPLAY_IN_FORMAT_16BITS_RGB565_1
#if defined (DISPLAY_IN_FORMAT_32BITS_RGB888_1) || defined (DISPLAY_IN_FORMAT_32BITS_ARGB8888_1)
            #define DISPLAY_BITS_PER_PIXEL_INPUT1 (32)
            #elif defined (DISPLAY_IN_FORMAT_16BITS_RGB565_1) || defined (DISPLAY_IN_FORMAT_16BITS_ARGB1555_1) || defined (DISPLAY_IN_FORMAT_16BITS_ARGB4444_1)
#define DISPLAY_BITS_PER_PIXEL_INPUT1 (16)
#elif defined (DISPLAY_IN_FORMAT_CLUT8_1)
            #define DISPLAY_BITS_PER_PIXEL_INPUT1 (8)
            #elif defined (DISPLAY_IN_FORMAT_CLUT4_1)
            #define DISPLAY_BITS_PER_PIXEL_INPUT1 (4)
            #else
            #define DISPLAY_BITS_PER_PIXEL_INPUT1 (1)
            #endif
#define DISPLAY_HSIZE_INPUT1                 (480)
#define DISPLAY_VSIZE_INPUT1                 (272)
#define DISPLAY_BUFFER_STRIDE_BYTES_INPUT1   (((DISPLAY_HSIZE_INPUT1 * DISPLAY_BITS_PER_PIXEL_INPUT1 + 0x1FF) >> 9) << 6)
#define DISPLAY_BUFFER_STRIDE_PIXELS_INPUT1  ((DISPLAY_BUFFER_STRIDE_BYTES_INPUT1 * 8) / DISPLAY_BITS_PER_PIXEL_INPUT1)
#if GLCDC_CFG_LAYER_2_ENABLE
            extern uint8_t fb_foreground[2][DISPLAY_BUFFER_STRIDE_BYTES_INPUT1 * DISPLAY_VSIZE_INPUT1];
            #endif
/* emWin physical display specs */
#define EMWIN_LCD_XSIZE_PHYS       (DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0)
#define EMWIN_LCD_YSIZE_PHYS       (272)

#if defined (DISPLAY_IN_FORMAT_32BITS_RGB888_0) || defined (DISPLAY_IN_FORMAT_32BITS_ARGB8888_0)
 #define EMWIN_LCD_BITS_PER_PIXEL   (32)
 #define EMWIN_LCD_DISPLAY_DRIVER   GUIDRV_LIN_32
 #if defined (DISPLAY_IN_FORMAT_32BITS_RGB888_0)
  #define EMWIN_LCD_COLOR_CONVERSION GUICC_M888
 #else
  #define EMWIN_LCD_COLOR_CONVERSION GUICC_M8888I
 #endif
#elif defined (DISPLAY_IN_FORMAT_16BITS_RGB565_0) || defined (DISPLAY_IN_FORMAT_16BITS_ARGB1555_0) || defined (DISPLAY_IN_FORMAT_16BITS_ARGB4444_0)
#define EMWIN_LCD_BITS_PER_PIXEL   (16)
#define EMWIN_LCD_DISPLAY_DRIVER   GUIDRV_LIN_16
#if defined (DISPLAY_IN_FORMAT_16BITS_RGB565_0)
#define EMWIN_LCD_COLOR_CONVERSION GUICC_M565
#elif defined (DISPLAY_IN_FORMAT_16BITS_ARGB1555_0)
  #define EMWIN_LCD_COLOR_CONVERSION GUICC_M1555I
 #else
  #define EMWIN_LCD_COLOR_CONVERSION GUICC_M4444I
 #endif
#elif defined (DISPLAY_IN_FORMAT_CLUT8_0)
 #define EMWIN_LCD_BITS_PER_PIXEL   (8)
 #define EMWIN_LCD_COLOR_CONVERSION GUICC_8666
 #define EMWIN_LCD_DISPLAY_DRIVER   GUIDRV_LIN_8
#elif defined (DISPLAY_IN_FORMAT_CLUT4_0)
 #define EMWIN_LCD_BITS_PER_PIXEL   (4)
 #define EMWIN_LCD_COLOR_CONVERSION GUICC_16
 #define EMWIN_LCD_DISPLAY_DRIVER   GUIDRV_LIN_4
#else
 #define EMWIN_LCD_BITS_PER_PIXEL   (1)
 #define EMWIN_LCD_COLOR_CONVERSION GUICC_1
 #define EMWIN_LCD_DISPLAY_DRIVER   GUIDRV_LIN_1
#endif

#define EMWIN_LCD_XSTRIDE_PHYS          (((EMWIN_LCD_XSIZE_PHYS * EMWIN_LCD_BITS_PER_PIXEL + 0x1FF) & 0xFFFFFE00) / EMWIN_LCD_BITS_PER_PIXEL)

#define EMWIN_LCD_FRAMEBUFFER_PTR       (fb_background[0])
#define EMWIN_LCD_NUM_FRAMEBUFFERS      (2)

/* Hardware acceleration macros */
#define RA_NOT_DEFINED    (1)
#if (RA_NOT_DEFINED == d2_handle0) || (EMWIN_LCD_BITS_PER_PIXEL < 16)
 #define EMWIN_LCD_USE_DAVE      (false)
 #define EMWIN_JPEG_USE_HW   (false)
#else
#define EMWIN_LCD_USE_DAVE      (true)
#if (RA_NOT_DEFINED == g_jpeg0)
  #define EMWIN_JPEG_USE_HW  (false)
 #else
#define EMWIN_JPEG_USE_HW  (true)
#endif
#endif
#undef RA_NOT_DEFINED
/* IOPORT Instance */
extern const ioport_instance_t g_ioport;

/* IOPORT control structure. */
extern ioport_instance_ctrl_t g_ioport_ctrl;
void g_common_init(void);
FSP_FOOTER
#endif /* COMMON_DATA_H_ */
