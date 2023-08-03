/* generated HAL source file - do not edit */
#include "hal_data.h"

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

  .p_callback = NULL,
  .p_ether_phy_instance = &g_ether_phy0, .p_context = NULL, .p_extend = NULL, };

/* Instance structure to use this module. */
const ether_instance_t g_ether0 =
{ .p_ctrl = &g_ether0_ctrl, .p_cfg = &g_ether0_cfg, .p_api = &g_ether_on_ether };
BSP_ALIGN_VARIABLE(16) edmac_desc_t g_edmac0_rx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;
BSP_ALIGN_VARIABLE(16) edmac_desc_t g_edmac0_tx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;

edmac_instance_ctrl_t g_edmac0_ctrl;
const edmac_cfg_t g_edmac0_cfg =
{ .channel = PTPC_EDMAC_CHANNEL, .padding = EDMAC_PADDING_DISABLE, .padding_offset = 0, .num_tx_desc = 4, .num_rx_desc =
          4,
  .p_tx_descriptors = g_edmac0_tx_descriptors, .p_rx_descriptors = g_edmac0_rx_descriptors, .p_callback =
          r_ptp_edmac_callback,
  .edmac_ipl = (12), .edmac_irq = VECTOR_NUMBER_EPTPC_PINT, .p_context = &g_ptp0, .p_extend = NULL };
edmac_instance_t g_edmac0 =
{ .p_ctrl = &g_edmac0_ctrl, .p_cfg = &g_edmac0_cfg };
/* Array for storing transmit packets. */
uint8_t g_ptp0_transmit_buffers[4][1536];
uint8_t *g_ptp0_transmit_buffer_array[4] =
{ (uint8_t*) &g_ptp0_transmit_buffers[0][0],
  (uint8_t*) &g_ptp0_transmit_buffers[1][0],
  (uint8_t*) &g_ptp0_transmit_buffers[2][0],
  (uint8_t*) &g_ptp0_transmit_buffers[3][0], };

/* Array for storing received packets. */
BSP_ALIGN_VARIABLE(32) uint8_t g_ptp0_receive_buffers[4][1536];uint8_t *g_ptp0_receive_buffer_array[4] =
{ (uint8_t*) &g_ptp0_receive_buffers[0][0],
  (uint8_t*) &g_ptp0_receive_buffers[1][0],
  (uint8_t*) &g_ptp0_receive_buffers[2][0],
  (uint8_t*) &g_ptp0_receive_buffers[3][0], };

/* If IPv4 packets are not used then provide destination MAC addresses. */
#if !0
static uint8_t g_ptp0_primary_mac_addr[] =
{ 0x01, 0x1B, 0x19, 0x00, 0x00, 0x00 };
static uint8_t g_ptp0_pdelay_mac_addr[] =
{ 0x01, 0x80, 0xC2, 0x00, 0x00, 0x0E };
#endif

/* Any multicast addresses that match the multicast filter address are transferred to the ETHERC EDMAC. */
static uint8_t g_ptp0_multicast_filter_addr[] =
{ 0x01, 0x1B, 0x19, 0x00, 0x00, 0x00 };

ptp_instance_ctrl_t g_ptp0_ctrl;

const ptp_cfg_t g_ptp0_cfg =
        { .synfp =
        { .ethernet_phy_interface = PTP_ETHERNET_PHY_INTERFACE_RMII,
          .frame_format = PTP_FRAME_FORMAT_ETHERII,
          .frame_filter = PTP_FRAME_FILTER_MODE_EXT_PROMISCUOUS_MODE,
          .clock_domain = 0,
          .clock_domain_filter = PTP_ENABLE,
          .announce_interval = PTP_MESSAGE_INTERVAL_1,
          .sync_interval = PTP_MESSAGE_INTERVAL_1,
          .delay_req_interval = PTP_MESSAGE_INTERVAL_1,
          .message_timeout = 4000,
          .clock_properties =
          { .priority1 = 128, .cclass = 248, .accuracy = 0xFE, .variance = 0xFFFF, .priority2 = 128 },
          .timesource = 160,
          .p_multicast_addr_filter = g_ptp0_multicast_filter_addr,
          /* If IPv4 packets are used. */
#if 0
        .ipv4 = {
            .primary_ip_addr = ((224U << 24U) | (0U << 16U) | (1U << 8U) | (129U << 0U)),
            .pdelay_ip_addr = ((224U << 24U) | (0U << 16U) | (0U << 8U) | (107U << 0U)),
            .event_tos = 0,
            .general_tos = 0,
            .primary_ttl = 1,
            .pdelay_ttl = 1,
            .event_udp_port = 319,
            .general_udp_port = 320,
        }
#else
          .ether =
          { .p_primary_mac_addr = g_ptp0_primary_mac_addr, .p_pdelay_mac_addr = g_ptp0_pdelay_mac_addr }
#endif
                  },
          .stca =
          { .clock_freq = PTP_STCA_CLOCK_FREQ_20MHZ,
            .clock_sel = PTP_STCA_CLOCK_SEL_PCLKA_DIV_6,
            .clock_correction_mode = PTP_CLOCK_CORRECTION_MODE1,
            .gradient_worst10_interval = 32,
            .sync_threshold =
            { .threshold = 1000000, .count = 5, },
            .sync_loss_threshold =
            { .threshold = 10000000, .count = 5, } },

          .mint_irq = VECTOR_NUMBER_EPTPC_MINT,
          .ipls_irq = VECTOR_NUMBER_EPTPC_IPLS, .mint_ipl = (12), .ipls_ipl = (12), .buffer_size = 1536, .p_rx_buffers =
                  g_ptp0_receive_buffer_array,
          .p_tx_buffers = g_ptp0_transmit_buffer_array, .p_edmac_instance = &g_edmac0, .p_callback = g_ptp0_callback, .p_context =
                  NULL,
          .p_extend = NULL };

ptp_instance_t g_ptp0 =
{ .p_ctrl = &g_ptp0_ctrl, .p_cfg = &g_ptp0_cfg, .p_api = &g_ptp_api };
void g_hal_init(void)
{
    g_common_init ();
}
