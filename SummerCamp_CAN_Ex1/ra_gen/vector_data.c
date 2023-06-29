/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [1] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [2] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [3] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [4] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
            [5] = can_error_isr, /* CAN1 ERROR (Error interrupt) */
            [6] = can_rx_isr, /* CAN1 MAILBOX RX (Reception complete interrupt) */
            [7] = can_tx_isr, /* CAN1 MAILBOX TX (Transmission complete interrupt) */
            [8] = can_rx_isr, /* CAN1 FIFO RX (Receive FIFO interrupt) */
            [9] = can_tx_isr, /* CAN1 FIFO TX (Transmit FIFO interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ11), /* ICU IRQ11 (External pin interrupt 11) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_CAN1_ERROR), /* CAN1 ERROR (Error interrupt) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_CAN1_MAILBOX_RX), /* CAN1 MAILBOX RX (Reception complete interrupt) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_CAN1_MAILBOX_TX), /* CAN1 MAILBOX TX (Transmission complete interrupt) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_CAN1_FIFO_RX), /* CAN1 FIFO RX (Receive FIFO interrupt) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_CAN1_FIFO_TX), /* CAN1 FIFO TX (Transmit FIFO interrupt) */
        };
        #endif
