/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = can_error_isr, /* CAN1 ERROR (Error interrupt) */
            [1] = can_rx_isr, /* CAN1 MAILBOX RX (Reception complete interrupt) */
            [2] = can_tx_isr, /* CAN1 MAILBOX TX (Transmission complete interrupt) */
            [3] = can_rx_isr, /* CAN1 FIFO RX (Receive FIFO interrupt) */
            [4] = can_tx_isr, /* CAN1 FIFO TX (Transmit FIFO interrupt) */
            [5] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
            [6] = agt_int_isr, /* AGT0 INT (AGT interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_CAN1_ERROR), /* CAN1 ERROR (Error interrupt) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_CAN1_MAILBOX_RX), /* CAN1 MAILBOX RX (Reception complete interrupt) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_CAN1_MAILBOX_TX), /* CAN1 MAILBOX TX (Transmission complete interrupt) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_CAN1_FIFO_RX), /* CAN1 FIFO RX (Receive FIFO interrupt) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_CAN1_FIFO_TX), /* CAN1 FIFO TX (Transmit FIFO interrupt) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ11), /* ICU IRQ11 (External pin interrupt 11) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_AGT0_INT), /* AGT0 INT (AGT interrupt) */
        };
        #endif
