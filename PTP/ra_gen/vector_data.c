/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = r_ptp_mint_isr, /* EPTPC MINT (SYNFP0/1 interrupt) */
            [1] = r_ptp_ipls_isr, /* EPTPC IPLS (STCA interrupt) */
            [2] = edmac_eint_isr, /* EPTPC PINT (PTPEDMAC interrupt) */
            [3] = ether_eint_isr, /* EDMAC0 EINT (EDMAC 0 interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_EPTPC_MINT), /* EPTPC MINT (SYNFP0/1 interrupt) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_EPTPC_IPLS), /* EPTPC IPLS (STCA interrupt) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_EPTPC_PINT), /* EPTPC PINT (PTPEDMAC interrupt) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_EDMAC0_EINT), /* EDMAC0 EINT (EDMAC 0 interrupt) */
        };
        #endif
