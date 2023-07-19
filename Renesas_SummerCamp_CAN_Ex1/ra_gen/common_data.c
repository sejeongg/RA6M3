/* generated common source file - do not edit */
#include "common_data.h"
#if JPEG_CFG_ENCODE_ENABLE

            /* Luminance quantization table */static const uint8_t quant_table_0[] ={16, 11, 10, 16, 24, 40, 51, 61, 12, 12, 14, 19, 26, 58, 60, 55, 14, 13, 16, 24, 40, 57, 69, 56, 14, 17, 22, 29, 51, 87, 80, 62, 18, 22, 37, 56, 68, 109, 103, 77, 24, 35, 55, 64, 81, 104, 113, 92, 49, 64, 78, 87, 103, 121, 120, 101, 72, 92, 95, 98, 112, 100, 103, 99, };/* Chrominance quantization table */static const uint8_t quant_table_1[] ={17, 18, 24, 47, 99, 99, 99, 99, 18, 21, 26, 66, 99, 99, 99, 99, 24, 26, 56, 99, 99, 99, 99, 99, 47, 66, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, };

            /* Luminance DC coefficients */
            static const uint8_t huffm_dc_table_0[] =
            {
                /* Table K.3 ITU-T81 specification */
                0x00, 0x01, 0x05, 0x01,
                0x01, 0x01, 0x01, 0x01,
                0x01, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x01, 0x02, 0x03,
                0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0A, 0x0B,
            };

            /* Chrominance DC coefficients */
            static const uint8_t huffm_dc_table_1[] =
            {
                /* Table K.4 ITU-T81 specification */
                0x00, 0x03, 0x01, 0x01,
                0x01, 0x01, 0x01, 0x01,
                0x01, 0x01, 0x01, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x01, 0x02, 0x03,
                0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0A, 0x0B,
            };

            /* Luminance AC coefficients */
            static const uint8_t huffm_ac_table_0[] =
            {
                /* Table K.5 ITU-T81 specification */
                0x00, 0x02, 0x01, 0x03,
                0x03, 0x02, 0x04, 0x03,
                0x05, 0x05, 0x04, 0x04,
                0x00, 0x00, 0x01, 0x7D,
                0x01, 0x02, 0x03, 0x00,
                0x04, 0x11, 0x05, 0x12,
                0x21, 0x31, 0x41, 0x06,
                0x13, 0x51, 0x61, 0x07,
                0x22, 0x71, 0x14, 0x32,
                0x81, 0x91, 0xA1, 0x08,
                0x23, 0x42, 0xB1, 0xC1,
                0x15, 0x52, 0xD1, 0xF0,
                0x24, 0x33, 0x62, 0x72,
                0x82, 0x09, 0x0A, 0x16,
                0x17, 0x18, 0x19, 0x1A,
                0x25, 0x26, 0x27, 0x28,
                0x29, 0x2A, 0x34, 0x35,
                0x36, 0x37, 0x38, 0x39,
                0x3A, 0x43, 0x44, 0x45,
                0x46, 0x47, 0x48, 0x49,
                0x4A, 0x53, 0x54, 0x55,
                0x56, 0x57, 0x58, 0x59,
                0x5A, 0x63, 0x64, 0x65,
                0x66, 0x67, 0x68, 0x69,
                0x6A, 0x73, 0x74, 0x75,
                0x76, 0x77, 0x78, 0x79,
                0x7A, 0x83, 0x84, 0x85,
                0x86, 0x87, 0x88, 0x89,
                0x8A, 0x92, 0x93, 0x94,
                0x95, 0x96, 0x97, 0x98,
                0x99, 0x9A, 0xA2, 0xA3,
                0xA4, 0xA5, 0xA6, 0xA7,
                0xA8, 0xA9, 0xAA, 0xB2,
                0xB3, 0xB4, 0xB5, 0xB6,
                0xB7, 0xB8, 0xB9, 0xBA,
                0xC2, 0xC3, 0xC4, 0xC5,
                0xC6, 0xC7, 0xC8, 0xC9,
                0xCA, 0xD2, 0xD3, 0xD4,
                0xD5, 0xD6, 0xD7, 0xD8,
                0xD9, 0xDA, 0xE1, 0xE2,
                0xE3, 0xE4, 0xE5, 0xE6,
                0xE7, 0xE8, 0xE9, 0xEA,
                0xF1, 0xF2, 0xF3, 0xF4,
                0xF5, 0xF6, 0xF7, 0xF8,
                0xF9, 0xFA,
            };

            /* Chrominance AC coefficients */
            static const uint8_t huffm_ac_table_1[] =
            {
                /* Table K.6 ITU-T81 specification */
                0x00, 0x02, 0x01, 0x02,
                0x04, 0x04, 0x03, 0x04,
                0x07, 0x05, 0x04, 0x04,
                0x00, 0x01, 0x02, 0x77,
                0x00, 0x01, 0x02, 0x03,
                0x11, 0x04, 0x05, 0x21,
                0x31, 0x06, 0x12, 0x41,
                0x51, 0x07, 0x61, 0x71,
                0x13, 0x22, 0x32, 0x81,
                0x08, 0x14, 0x42, 0x91,
                0xA1, 0xB1, 0xC1, 0x09,
                0x23, 0x33, 0x52, 0xF0,
                0x15, 0x62, 0x72, 0xD1,
                0x0A, 0x16, 0x24, 0x34,
                0xE1, 0x25, 0xF1, 0x17,
                0x18, 0x19, 0x1A, 0x26,
                0x27, 0x28, 0x29, 0x2A,
                0x35, 0x36, 0x37, 0x38,
                0x39, 0x3A, 0x43, 0x44,
                0x45, 0x46, 0x47, 0x48,
                0x49, 0x4A, 0x53, 0x54,
                0x55, 0x56, 0x57, 0x58,
                0x59, 0x5A, 0x63, 0x64,
                0x65, 0x66, 0x67, 0x68,
                0x69, 0x6A, 0x73, 0x74,
                0x75, 0x76, 0x77, 0x78,
                0x79, 0x7A, 0x82, 0x83,
                0x84, 0x85, 0x86, 0x87,
                0x88, 0x89, 0x8A, 0x92,
                0x93, 0x94, 0x95, 0x96,
                0x97, 0x98, 0x99, 0x9A,
                0xA2, 0xA3, 0xA4, 0xA5,
                0xA6, 0xA7, 0xA8, 0xA9,
                0xAA, 0xB2, 0xB3, 0xB4,
                0xB5, 0xB6, 0xB7, 0xB8,
                0xB9, 0xBA, 0xC2, 0xC3,
                0xC4, 0xC5, 0xC6, 0xC7,
                0xC8, 0xC9, 0xCA, 0xD2,
                0xD3, 0xD4, 0xD5, 0xD6,
                0xD7, 0xD8, 0xD9, 0xDA,
                0xE2, 0xE3, 0xE4, 0xE5,
                0xE6, 0xE7, 0xE8, 0xE9,
                0xEA, 0xF2, 0xF3, 0xF4,
                0xF5, 0xF6, 0xF7, 0xF8,
                0xF9, 0xFA,
            };
            #endif

jpeg_instance_ctrl_t g_jpeg0_ctrl;
const jpeg_cfg_t g_jpeg0_cfg =
{ .jedi_ipl = (4), .jdti_ipl = (12),
#if defined(VECTOR_NUMBER_JPEG_JEDI)
                .jedi_irq           = VECTOR_NUMBER_JPEG_JEDI,
            #else
  .jedi_irq = FSP_INVALID_VECTOR,
#endif
  .jdti_irq = VECTOR_NUMBER_JPEG_JDTI,

#if JPEG_CFG_DECODE_ENABLE && JPEG_CFG_ENCODE_ENABLE
                .default_mode              = (JPEG_MODE_DECODE),
            #endif

#if JPEG_CFG_DECODE_ENABLE
                .decode_input_data_order   = JPEG_DATA_ORDER_NORMAL,
                .decode_output_data_order  = JPEG_DATA_ORDER_NORMAL,
                .pixel_format              = JPEG_DECODE_PIXEL_FORMAT_RGB565,
                .alpha_value               = 255,
                .p_decode_callback         = _JPEGDecodeCallback,
                .p_decode_context          = NULL,
            #endif

#if JPEG_CFG_ENCODE_ENABLE
                .encode_input_data_order   = JPEG_DATA_ORDER_NORMAL,
                .encode_output_data_order  = JPEG_DATA_ORDER_NORMAL,
                .dri_marker                = 512,
                .horizontal_resolution     = 480,
                .vertical_resolution       = 272,
                .horizontal_stride_pixels  = 480,
                .p_quant_luma_table        = quant_table_0,
                .p_quant_chroma_table      = quant_table_1,
                .p_huffman_luma_ac_table   = huffm_ac_table_0,
                .p_huffman_luma_dc_table   = huffm_dc_table_0,
                .p_huffman_chroma_ac_table = huffm_ac_table_1,
                .p_huffman_chroma_dc_table = huffm_dc_table_1,
                .p_encode_callback         = NULL,
                .p_encode_context          = NULL,
            #endif
        };

const jpeg_instance_t g_jpeg0 =
{ .p_api = (jpeg_api_t const*) &g_jpeg_on_jpeg, .p_ctrl = &g_jpeg0_ctrl, .p_cfg = &g_jpeg0_cfg };
const uint8_t DRW_INT_IPL = (2);
d2_device *d2_handle0;
/** Display framebuffer */
#if GLCDC_CFG_LAYER_1_ENABLE
        uint8_t fb_background[2][DISPLAY_BUFFER_STRIDE_BYTES_INPUT0 * DISPLAY_VSIZE_INPUT0] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".bss");
        #else
/** Graphics Layer 1 is specified not to be used when starting */
#endif
#if GLCDC_CFG_LAYER_2_ENABLE
        uint8_t fb_foreground[2][DISPLAY_BUFFER_STRIDE_BYTES_INPUT1 * DISPLAY_VSIZE_INPUT1] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".bss");
        #else
/** Graphics Layer 2 is specified not to be used when starting */
#endif

#if GLCDC_CFG_CLUT_ENABLE
        /** Display CLUT buffer to be used for updating CLUT */
        static uint32_t CLUT_buffer[256];

        /** Display CLUT configuration(only used if using CLUT format) */
        display_clut_cfg_t g_display0_clut_cfg_glcdc =
        {
            .p_base              = (uint32_t *)CLUT_buffer,
            .start               = 0,   /* User have to update this setting when using */
            .size                = 256  /* User have to update this setting when using */
        };
        #else
/** CLUT is specified not to be used */
#endif

#if (false)
         #define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST   const
         #define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST    (uint16_t *)
         #define GLCDC_CFG_CORRECTION_GAMMA_CFG_CAST      (display_gamma_correction_t *)
        #else
#define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST
#define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST
#define GLCDC_CFG_CORRECTION_GAMMA_CFG_CAST
#endif

#if ((GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B) && GLCDC_CFG_COLOR_CORRECTION_ENABLE)
        /** Gamma correction tables */
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_r_gain[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_r_threshold[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960};
        #endif
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_g_gain[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_g_threshold[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960};
        #endif
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_b_gain[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_b_threshold[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960};
        #endif
        GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST display_gamma_correction_t g_display0_gamma_cfg =
        {
            .r =
            {
                .enable      = GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R,
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R
                .gain        = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_r_gain,
                .threshold   = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_r_threshold
        #else
                .gain        = NULL,
                .threshold   = NULL
        #endif
            },
            .g =
            {
                .enable      = GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G,
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G
                .gain        = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_g_gain,
                .threshold   = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_g_threshold
        #else
                .gain        = NULL,
                .threshold   = NULL
        #endif
            },
            .b =
            {
                .enable      = GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B,
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B
                .gain        = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_b_gain,
                .threshold   = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_b_threshold
        #else
                .gain        = NULL,
                .threshold   = NULL
        #endif
            }
        };
        #endif

/** Display device extended configuration */
const glcdc_extended_cfg_t g_display0_extend_cfg =
{ .tcon_hsync = GLCDC_TCON_PIN_0,
  .tcon_vsync = GLCDC_TCON_PIN_1,
  .tcon_de = GLCDC_TCON_PIN_2,
  .correction_proc_order = GLCDC_CORRECTION_PROC_ORDER_BRIGHTNESS_CONTRAST2GAMMA,
  .clksrc = GLCDC_CLK_SRC_INTERNAL,
  .clock_div_ratio = GLCDC_PANEL_CLK_DIVISOR_24,
  .dithering_mode = GLCDC_DITHERING_MODE_TRUNCATE,
  .dithering_pattern_A = GLCDC_DITHERING_PATTERN_11,
  .dithering_pattern_B = GLCDC_DITHERING_PATTERN_11,
  .dithering_pattern_C = GLCDC_DITHERING_PATTERN_11,
  .dithering_pattern_D = GLCDC_DITHERING_PATTERN_11 };

/** Display control block instance */
glcdc_instance_ctrl_t g_display0_ctrl;

/** Display interface configuration */
const display_cfg_t g_display0_cfg =
        {
        /** Input1(Graphics1 layer) configuration */
        .input[0] =
        {
#if GLCDC_CFG_LAYER_1_ENABLE
                .p_base              = (uint32_t *)&fb_background[0],
                #else
          .p_base = NULL,
#endif
          .hsize = DISPLAY_HSIZE_INPUT0,
          .vsize = DISPLAY_VSIZE_INPUT0, .hstride = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0, .format =
                  DISPLAY_IN_FORMAT_16BITS_RGB565,
          .line_descending_enable = false, .lines_repeat_enable = false, .lines_repeat_times = 0 },

          /** Input2(Graphics2 layer) configuration */
          .input[1] =
          {
#if GLCDC_CFG_LAYER_2_ENABLE
                .p_base              = (uint32_t *)&fb_foreground[0],
                #else
            .p_base = NULL,
#endif
            .hsize = DISPLAY_HSIZE_INPUT1,
            .vsize = DISPLAY_VSIZE_INPUT1, .hstride = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT1, .format =
                    DISPLAY_IN_FORMAT_16BITS_RGB565,
            .line_descending_enable = false, .lines_repeat_enable = false, .lines_repeat_times = 0 },

          /** Input1(Graphics1 layer) layer configuration */
          .layer[0] =
          { .coordinate =
          { .x = 0, .y = 0 },
            .bg_color =
            { .byte =
            { .a = 255, .r = 255, .g = 255, .b = 255 } },
            .fade_control = DISPLAY_FADE_CONTROL_NONE, .fade_speed = 0 },

          /** Input2(Graphics2 layer) layer configuration */
          .layer[1] =
          { .coordinate =
          { .x = 0, .y = 0 },
            .bg_color =
            { .byte =
            { .a = 255, .r = 255, .g = 255, .b = 255 } },
            .fade_control = DISPLAY_FADE_CONTROL_NONE, .fade_speed = 0 },

          /** Output configuration */
          .output =
                  { .htiming =
                  { .total_cyc = 525, .display_cyc = 480, .back_porch = 40, .sync_width = 1, .sync_polarity =
                            DISPLAY_SIGNAL_POLARITY_LOACTIVE },
                    .vtiming =
                    { .total_cyc = 316, .display_cyc = 272, .back_porch = 8, .sync_width = 1, .sync_polarity =
                              DISPLAY_SIGNAL_POLARITY_LOACTIVE },
                    .format = DISPLAY_OUT_FORMAT_16BITS_RGB565, .endian = DISPLAY_ENDIAN_LITTLE, .color_order =
                            DISPLAY_COLOR_ORDER_RGB,
                    .data_enable_polarity = DISPLAY_SIGNAL_POLARITY_HIACTIVE, .sync_edge =
                            DISPLAY_SIGNAL_SYNC_EDGE_RISING,
                    .bg_color =
                    { .byte =
                    { .a = 255, .r = 0, .g = 0, .b = 0 } },
#if (GLCDC_CFG_COLOR_CORRECTION_ENABLE)
                .brightness =
                {
                    .enable          = false,
                    .r               = 512,
                    .g               = 512,
                    .b               = 512
                },
                .contrast =
                {
                    .enable          = false,
                    .r               = 128,
                    .g               = 128,
                    .b               = 128
                },
#if (GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B)
 #if false
                .p_gamma_correction  = GLCDC_CFG_CORRECTION_GAMMA_CFG_CAST (&g_display0_gamma_cfg),
 #else
                .p_gamma_correction  = &g_display0_gamma_cfg,
 #endif
#else
                .p_gamma_correction  = NULL,
#endif
#endif
                    .dithering_on = false },

          /** Display device callback function pointer */
          .p_callback = _DisplayVsyncCallback,
          .p_context = NULL,

          /** Display device extended configuration */
          .p_extend = (void*) (&g_display0_extend_cfg),

          .line_detect_ipl = (2),
          .underflow_1_ipl = (BSP_IRQ_DISABLED), .underflow_2_ipl = (BSP_IRQ_DISABLED),

#if defined(VECTOR_NUMBER_GLCDC_LINE_DETECT)
            .line_detect_irq        = VECTOR_NUMBER_GLCDC_LINE_DETECT,
#else
          .line_detect_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GLCDC_UNDERFLOW_1)
            .underflow_1_irq        = VECTOR_NUMBER_GLCDC_UNDERFLOW_1,
#else
          .underflow_1_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GLCDC_UNDERFLOW_2)
            .underflow_2_irq        = VECTOR_NUMBER_GLCDC_UNDERFLOW_2,
#else
          .underflow_2_irq = FSP_INVALID_VECTOR,
#endif
        };

#if GLCDC_CFG_LAYER_1_ENABLE
        /** Display on GLCDC run-time configuration(for the graphics1 layer) */
        display_runtime_cfg_t g_display0_runtime_cfg_bg =
        {
            .input =
            {
                #if (true)
                .p_base              = (uint32_t *)&fb_background[0],
                #else
                .p_base              = NULL,
                #endif
                .hsize               = DISPLAY_HSIZE_INPUT0,
                .vsize               = DISPLAY_VSIZE_INPUT0,
                .hstride             = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0,
                .format              = DISPLAY_IN_FORMAT_16BITS_RGB565,
                .line_descending_enable = false,
                .lines_repeat_enable = false,
                .lines_repeat_times  = 0
            },
            .layer =
            {
                .coordinate = {
                        .x           = 0,
                        .y           = 0
                },
                .bg_color            =
                {
                    .byte            =
                    {
                        .a           = 255,
                        .r           = 255,
                        .g           = 255,
                        .b           = 255
                    }
                },
                .fade_control        = DISPLAY_FADE_CONTROL_NONE,
                .fade_speed          = 0
            }
        };
#endif
#if GLCDC_CFG_LAYER_2_ENABLE
        /** Display on GLCDC run-time configuration(for the graphics2 layer) */
        display_runtime_cfg_t g_display0_runtime_cfg_fg =
        {
            .input =
            {
                #if (false)
                .p_base              = (uint32_t *)&fb_foreground[0],
                #else
                .p_base              = NULL,
                #endif
                .hsize               = DISPLAY_HSIZE_INPUT1,
                .vsize               = DISPLAY_VSIZE_INPUT1,
                .hstride             = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT1,
                .format              = DISPLAY_IN_FORMAT_16BITS_RGB565,
                .line_descending_enable = false,
                .lines_repeat_enable = false,
                .lines_repeat_times  = 0
             },
            .layer =
            {
                .coordinate = {
                        .x           = 0,
                        .y           = 0
                },
                .bg_color            =
                {
                    .byte            =
                    {
                        .a           = 255,
                        .r           = 255,
                        .g           = 255,
                        .b           = 255
                    }
                },
                .fade_control        = DISPLAY_FADE_CONTROL_NONE,
                .fade_speed          = 0
            }
        };
#endif

/* Instance structure to use this module. */
const display_instance_t g_display0 =
{ .p_ctrl = &g_display0_ctrl, .p_cfg = (display_cfg_t*) &g_display0_cfg, .p_api = (display_api_t*) &g_display_on_glcdc };
display_instance_t const *_g_display_emwin = &g_display0;

#if EMWIN_LCD_USE_DAVE
d2_device ** _d2_handle_emwin = &d2_handle0;
#if EMWIN_JPEG_USE_HW
jpeg_instance_t const * _g_jpeg_emwin_decode = &g_jpeg0;
#endif
#endif

uint8_t *_fb_emwin;
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
{ .p_api = &g_ioport_on_ioport, .p_ctrl = &g_ioport_ctrl, .p_cfg = &g_bsp_pin_cfg, };
void g_common_init(void)
{
}
