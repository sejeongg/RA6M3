/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_icu.h"
#include "r_external_irq_api.h"
#include "r_agt.h"
#include "r_timer_api.h"
#include "r_ether_phy.h"
#include "r_ether_phy_api.h"
#include "r_ether.h"
#include "r_ether_api.h"
FSP_HEADER
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq14;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq14_ctrl;
extern const external_irq_cfg_t g_external_irq14_cfg;

#ifndef R_External_Interrupt
void R_External_Interrupt(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq13;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq13_ctrl;
extern const external_irq_cfg_t g_external_irq13_cfg;

#ifndef R_External_Interrupt
void R_External_Interrupt(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq12;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq12_ctrl;
extern const external_irq_cfg_t g_external_irq12_cfg;

#ifndef R_External_Interrupt
void R_External_Interrupt(external_irq_callback_args_t *p_args);
#endif
/** AGT Timer Instance */
extern const timer_instance_t g_timer0;

/** Access the AGT instance using these structures when calling API functions directly (::p_api is not used). */
extern agt_instance_ctrl_t g_timer0_ctrl;
extern const timer_cfg_t g_timer0_cfg;

#ifndef R_AGT0_Interrupt
void R_AGT0_Interrupt(timer_callback_args_t *p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq11;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq11_ctrl;
extern const external_irq_cfg_t g_external_irq11_cfg;

#ifndef R_External_Interrupt
void R_External_Interrupt(external_irq_callback_args_t *p_args);
#endif
/** ether_phy on ether_phy Instance. */
extern const ether_phy_instance_t g_ether_phy0;

/** Access the Ethernet PHY instance using these structures when calling API functions directly (::p_api is not used). */
extern ether_phy_instance_ctrl_t g_ether_phy0_ctrl;
extern const ether_phy_cfg_t g_ether_phy0_cfg;
#if (BSP_FEATURE_TZ_HAS_TRUSTZONE == 1) && (BSP_TZ_SECURE_BUILD != 1) && (BSP_TZ_NONSECURE_BUILD != 1)
#define ETHER_BUFFER_PLACE_IN_SECTION BSP_PLACE_IN_SECTION(".ns_buffer.eth")
#else
#define ETHER_BUFFER_PLACE_IN_SECTION
#endif

/** ether on ether Instance. */
extern const ether_instance_t g_ether0;

/** Access the Ethernet instance using these structures when calling API functions directly (::p_api is not used). */
extern ether_instance_ctrl_t g_ether0_ctrl;
extern const ether_cfg_t g_ether0_cfg;

#ifndef R_Ethernet_RxInterrupt
void R_Ethernet_RxInterrupt(ether_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
