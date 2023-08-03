/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_ether_phy.h"
#include "r_ether_phy_api.h"
#include "r_ether.h"
#include "r_ether_api.h"

#include "r_ptp.h"
FSP_HEADER
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

#ifndef NULL
void NULL(ether_callback_args_t *p_args);
#endif
extern void r_ptp_edmac_callback(edmac_callback_args_t *p_args);
extern edmac_instance_ctrl_t g_edmac0_ctrl;
extern const edmac_cfg_t g_edmac0_cfg;
extern edmac_instance_t g_edmac0;
extern void g_ptp0_callback(ptp_callback_args_t *p_args);
extern void ptp_edmac_callback(edmac_callback_args_t *p_args);

extern ptp_instance_ctrl_t g_ptp0_ctrl;
extern const ptp_cfg_t g_ptp0_cfg;
extern ptp_instance_t g_ptp0;
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
