/*
 * g_ethernet_lib.c
 *
 *  Created on: 2023. 3. 7.
 *      Author: Jonghun Kim
 */

#include <g_Ethernet.h>

extern ethFrameStr          TxFrameBuffer;
extern ethFrameStr          RxFrameBuffer;
uint32_t                    TxFrameSize = 0;               // Length(Size) of Transmitted Ethernet Message

void R_Eth_Initial_Setting()
{
    fsp_err_t err = FSP_SUCCESS;

    R_ETHER_Open(&g_ether0_ctrl, &g_ether0_cfg);
    R_ETHERC_EDMAC->EESIPR_b.TCIP = 0U; // Disable Transmit Interrupt Setting

    do {
        err = R_ETHER_LinkProcess(&g_ether0_ctrl);
    } while (FSP_SUCCESS != err);

    memset(&RxFrameBuffer, 0, sizeof(ethFrameStr));

    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_10_PIN_08, BSP_IO_LEVEL_LOW);
}

//uint16_t calChecksum()
//{
//    uint16_t *ptr = NULL;
//    uint32_t checksum = 0;
//
//    for (uint8_t idx = 0; idx < ETH_IP_HEADER_SIZE / 2; idx++)
//    {
//        ptr = (uint16_t *)(TxFrameBuffer.dstMAC + ETH_MAC_HEAD_SIZE + (idx * IP_CHECKSUM_UNIT));
//        checksum += (uint16_t)(*ptr << STRUCT_SHIFT_SIZE) | (uint16_t)(*ptr >> STRUCT_SHIFT_SIZE); // Consider Little Endian Format of Register
//    }
//
//    checksum = ~((checksum & FULL_MASK_16BIT) + checksum / IP_CHECKSUM_DIV);
//
//    return (uint16_t)checksum;
//}
//eth_ip_checksum verChecksum()
//{
//    uint16_t *ptr = NULL;
//    uint32_t checksum = 0;
//
//    for (uint8_t idx = 0; idx < ETH_IP_HEADER_SIZE / 2; idx++)
//    {
//        ptr = (uint16_t *)(RxFrameBuffer.dstMAC + ETH_MAC_HEAD_SIZE + (idx * IP_CHECKSUM_UNIT));
//        checksum += (uint16_t)(*ptr << STRUCT_SHIFT_SIZE) | (uint16_t)(*ptr >> STRUCT_SHIFT_SIZE); // Consider Little Endian Format of Register
//    }
//
//    checksum = ~(checksum + checksum / IP_CHECKSUM_DIV);
//
//    if ((checksum & FULL_MASK_16BIT) == 0)
//        return correct_checksum;
//    else return wrong_checksum;
//}

void setLayer2(uint8_t *dMAC, uint8_t *sMAC)
{
    // Ethernet Frame Destination & Source MAC Address Setting //
    memcpy(&TxFrameBuffer.dstMAC[0], dMAC, ETH_MAC_ADDR_SIZE);
    memcpy(&TxFrameBuffer.srcMAC[0], sMAC, ETH_MAC_ADDR_SIZE);

    // Ethernet Frame VLAN Type Setting: 0x8100 //
    TxFrameBuffer.VLANType[0] = (uint8_t)(ETH_VLAN_TYPE >> STRUCT_SHIFT_SIZE);
    TxFrameBuffer.VLANType[1] = (uint8_t)(ETH_VLAN_TYPE & FULL_MASK_8BIT);

    // Ethernet Frame VLAN Security Setting //
    TxFrameBuffer.PRI = VLAN_PRI;
    TxFrameBuffer.DEI = VLAN_DEI;
    TxFrameBuffer.IDH = VLAN_ID >> STRUCT_SHIFT_SIZE;
    TxFrameBuffer.IDL = VLAN_ID & 0xFF;

    // Ethernet Frame Type & Length Setting: IPv4 [0x0800] //
    TxFrameBuffer.ethType[0] = (uint8_t)(ETH_IPv4_TYPE >> STRUCT_SHIFT_SIZE);
    TxFrameBuffer.ethType[1] = (uint8_t)(ETH_IPv4_TYPE & FULL_MASK_8BIT);
}

//void setLayer3(uint8_t *dIP, uint8_t *sIP)
//{
//    // Ethernet Packet IP Header Setting //
//    TxFrameBuffer.IPV = ETH_IPV_IPv4;
//    TxFrameBuffer.IHL = ETH_IHL_5;
//    TxFrameBuffer.DSCP = ETH_DSCP_INIT;
//    TxFrameBuffer.ECN = ETH_ECN_INIT;
//
//    TxFrameBuffer.TotalLen[0] = 0;
//    TxFrameBuffer.TotalLen[1] = 0x47;
//
//    TxFrameBuffer.GroupID[0] = ETH_IP_GID >> STRUCT_SHIFT_SIZE;
//    TxFrameBuffer.GroupID[1] = ETH_IP_GID & FULL_MASK_8BIT;
//
//    TxFrameBuffer.fragInfo[0] = ETH_NonFrag | (ETH_FragOffset >> STRUCT_SHIFT_SIZE);
//    TxFrameBuffer.fragInfo[1] = ETH_FragOffset & FULL_MASK_8BIT;
//
//    TxFrameBuffer.TTL = ETH_TTL_INIT;
//    TxFrameBuffer.Protocol = ETH_UDP_PROT;
//
//    // Ethernet Packet Destination & Source IP Address Setting //
//    memcpy(&TxFrameBuffer.dstIP[0], dIP, ETH_IP_ADDR_SIZE);
//    memcpy(&TxFrameBuffer.srcIP[0], sIP, ETH_IP_ADDR_SIZE);
//
//    uint16_t checksum = calChecksum();
//
//    TxFrameBuffer.ICS[0] = (uint8_t)(checksum >> STRUCT_SHIFT_SIZE);
//    TxFrameBuffer.ICS[1] = (uint8_t)(checksum & FULL_MASK_8BIT);
//
//    memset(TxFrameBuffer.payload, 0, sizeof(TxFrameBuffer.payload));
//}

void setEthFrame(uint8_t *dMAC, uint8_t *sMAC)
{
    setLayer2(dMAC, sMAC);
}
