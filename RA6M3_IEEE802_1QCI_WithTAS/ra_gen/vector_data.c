/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = ether_eint_isr, /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [1] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
            [2] = agt_int_isr, /* AGT0 INT (AGT interrupt) */
            [3] = r_icu_isr, /* ICU IRQ12 (External pin interrupt 12) */
            [4] = r_icu_isr, /* ICU IRQ13 (External pin interrupt 13) */
            [5] = r_icu_isr, /* ICU IRQ14 (External pin interrupt 14) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_EDMAC0_EINT), /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ11), /* ICU IRQ11 (External pin interrupt 11) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_AGT0_INT), /* AGT0 INT (AGT interrupt) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ12), /* ICU IRQ12 (External pin interrupt 12) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ13), /* ICU IRQ13 (External pin interrupt 13) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ14), /* ICU IRQ14 (External pin interrupt 14) */
        };
        #endif
