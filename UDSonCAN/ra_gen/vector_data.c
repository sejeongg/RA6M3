/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
            [1] = can_error_isr, /* CAN1 ERROR (Error interrupt) */
            [2] = can_rx_isr, /* CAN1 MAILBOX RX (Reception complete interrupt) */
            [3] = can_tx_isr, /* CAN1 MAILBOX TX (Transmission complete interrupt) */
            [4] = can_rx_isr, /* CAN1 FIFO RX (Receive FIFO interrupt) */
            [5] = can_tx_isr, /* CAN1 FIFO TX (Transmit FIFO interrupt) */
            [6] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [7] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [8] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [9] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [10] = glcdc_line_detect_isr, /* GLCDC LINE DETECT (Specified line) */
            [11] = drw_int_isr, /* DRW INT (Display list interrupt) */
            [12] = jpeg_jedi_isr, /* JPEG JEDI (Compression/decompression process interrupt) */
            [13] = jpeg_jdti_isr, /* JPEG JDTI (Data transfer interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ11), /* ICU IRQ11 (External pin interrupt 11) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_CAN1_ERROR), /* CAN1 ERROR (Error interrupt) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_CAN1_MAILBOX_RX), /* CAN1 MAILBOX RX (Reception complete interrupt) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_CAN1_MAILBOX_TX), /* CAN1 MAILBOX TX (Transmission complete interrupt) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_CAN1_FIFO_RX), /* CAN1 FIFO RX (Receive FIFO interrupt) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_CAN1_FIFO_TX), /* CAN1 FIFO TX (Transmit FIFO interrupt) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_GLCDC_LINE_DETECT), /* GLCDC LINE DETECT (Specified line) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_DRW_INT), /* DRW INT (Display list interrupt) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_JPEG_JEDI), /* JPEG JEDI (Compression/decompression process interrupt) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_JPEG_JDTI), /* JPEG JDTI (Data transfer interrupt) */
        };
        #endif
