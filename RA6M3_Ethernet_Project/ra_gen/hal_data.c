/* generated HAL source file - do not edit */
#include "hal_data.h"

icu_instance_ctrl_t g_external_irq12_ctrl;
const external_irq_cfg_t g_external_irq12_cfg =
{ .channel = 12,
  .trigger = EXTERNAL_IRQ_TRIG_FALLING,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = R_IRQ_Callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ12)
    .irq                 = VECTOR_NUMBER_ICU_IRQ12,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq12 =
{ .p_ctrl = &g_external_irq12_ctrl, .p_cfg = &g_external_irq12_cfg, .p_api = &g_external_irq_on_icu };
icu_instance_ctrl_t g_external_irq11_ctrl;
const external_irq_cfg_t g_external_irq11_cfg =
{ .channel = 11,
  .trigger = EXTERNAL_IRQ_TRIG_FALLING,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = R_IRQ_Callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ11)
    .irq                 = VECTOR_NUMBER_ICU_IRQ11,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq11 =
{ .p_ctrl = &g_external_irq11_ctrl, .p_cfg = &g_external_irq11_cfg, .p_api = &g_external_irq_on_icu };
ether_phy_instance_ctrl_t g_ether_phy0_ctrl;

const ether_phy_cfg_t g_ether_phy0_cfg =
{

.channel = 0,
  .phy_lsi_address = 0, .phy_reset_wait_time = 0x00020000, .mii_bit_access_wait_time = 8, .flow_control =
          ETHER_PHY_FLOW_CONTROL_DISABLE,
  .mii_type = ETHER_PHY_MII_TYPE_RMII, .p_context = NULL, .p_extend = NULL,

};
/* Instance structure to use this module. */
const ether_phy_instance_t g_ether_phy0 =
{ .p_ctrl = &g_ether_phy0_ctrl, .p_cfg = &g_ether_phy0_cfg, .p_api = &g_ether_phy_on_ether_phy };
ether_instance_ctrl_t g_ether0_ctrl;

uint8_t g_ether0_mac_address[6] =
{ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 };

__attribute__((__aligned__(16))) ether_instance_descriptor_t g_ether0_tx_descriptors[1] ETHER_BUFFER_PLACE_IN_SECTION;
__attribute__((__aligned__(16))) ether_instance_descriptor_t g_ether0_rx_descriptors[1] ETHER_BUFFER_PLACE_IN_SECTION;

__attribute__((__aligned__(32)))uint8_t g_ether0_ether_buffer0[1536]ETHER_BUFFER_PLACE_IN_SECTION;
__attribute__((__aligned__(32)))uint8_t g_ether0_ether_buffer1[1536]ETHER_BUFFER_PLACE_IN_SECTION;

uint8_t *pp_g_ether0_ether_buffers[2] =
{ (uint8_t*) &g_ether0_ether_buffer0[0], (uint8_t*) &g_ether0_ether_buffer1[0], };

const ether_cfg_t g_ether0_cfg =
{ .channel = 0, .zerocopy = ETHER_ZEROCOPY_DISABLE, .multicast = ETHER_MULTICAST_ENABLE, .promiscuous =
          ETHER_PROMISCUOUS_DISABLE,
  .flow_control = ETHER_FLOW_CONTROL_DISABLE, .padding = ETHER_PADDING_DISABLE, .padding_offset = 0, .broadcast_filter =
          0,
  .p_mac_address = g_ether0_mac_address,

  .p_rx_descriptors = g_ether0_rx_descriptors,
  .p_tx_descriptors = g_ether0_tx_descriptors,

  .num_tx_descriptors = 1,
  .num_rx_descriptors = 1,

  .pp_ether_buffers = pp_g_ether0_ether_buffers,

  .ether_buffer_size = 1536,

#if defined(VECTOR_NUMBER_EDMAC0_EINT)
                .irq                = VECTOR_NUMBER_EDMAC0_EINT,
#else
  .irq = FSP_INVALID_VECTOR,
#endif

  .interrupt_priority = (12),

  .p_callback = R_Eth_Callback,
  .p_ether_phy_instance = &g_ether_phy0, .p_context = NULL, .p_extend = NULL, };

/* Instance structure to use this module. */
const ether_instance_t g_ether0 =
{ .p_ctrl = &g_ether0_ctrl, .p_cfg = &g_ether0_cfg, .p_api = &g_ether_on_ether };
void g_hal_init(void)
{
    g_common_init ();
}
