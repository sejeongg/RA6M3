/*
 * g_ethernet_lib.h
 *
 *  Created on: 2023. 3. 7.
 *      Author: Jonghun Kim
 */

#include <hal_data.h>

#ifndef G_ETHERNET_LIB_H_
#define G_ETHERNET_LIB_H_

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// USER DEFINITION AREA (Ethernet Parameters) ////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

#define ETH_MTU_SIZE                    1500                    // Ethernet II Frame Maximum Transmission Unit Size

#define VLAN_PRI                        0b001                   // [15:13] VLAN Priority Code Point (3-bit)
#define VLAN_DEI                        0b1                     // [12:12] VLAN Drop Eligible Indicator (1-bit)
#define VLAN_ID                         0b000000110000          // [11: 0] VLAN Identifier (12-bit)

#define ETH_IP_HEADER_SIZE              20                      // Initial Setting (No use IP Header Options)
#define ETH_DSCP_INIT                   0b000000
#define ETH_ECN_INIT                    0b00

#define ETH_IP_GID                      0x0001

#define ETH_TTL_INIT                    0x0A

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

#define STRUCT_SHIFT_SIZE               8
#define FULL_MASK_8BIT                  0xFF
#define FULL_MASK_16BIT                 0xFFFF
#define FULL_MASK_32BIT                 0xFFFFFFFF

#define IP_CHECKSUM_UNIT                2
#define IP_CHECKSUM_DIV                 65536

#define ETH_MAC_ADDR_SIZE               6                       // Ethernet II Frame MAC Address Size
#define ETH_IP_ADDR_SIZE                4                       // Ethernet IP Address Size
#define ETH_TYPE_SIZE                   2                       // Ethernet II Frame Type Size
#define ETH_VLAN_TAG_COUNT              3                       // Ethernet VLAN Tag Component Count

#define ETH_MAC_HEAD_SIZE               (ETH_MAC_ADDR_SIZE * 2 + ETH_TYPE_SIZE * 3)
#define ETH_FRAME_SIZE                  (ETH_MAC_HEAD_SIZE + ETH_MTU_SIZE)

#define ETH_VLAN_TYPE                   0x8100
#define ETH_IPv4_TYPE                   0x0800

#define ETH_IPV_IPv4                    0b0100
#define ETH_IPV_IPv6                    0b0110

#define ETH_IHL_5                       0b0101
#define ETH_IHL_6                       0b0110
#define ETH_IHL_7                       0b0111
#define ETH_IHL_8                       0b1000

#define ETH_NonFrag                     0x40
#define ETH_MulFrag                     0x20
#define ETH_FragOffset                  0x0000

#define ETH_ICMP_PROT                   0x01
#define ETH_IGMP_PROT                   0x02
#define ETH_TCP_PROT                    0x06
#define ETH_UDP_PROT                    0x11

typedef enum    _eth_ip_checksum    eth_ip_checksum;
typedef struct  _ethFrameStr        ethFrameStr;

void R_Eth_Initial_Setting();
//uint16_t calChecksum();
//eth_ip_checksum verChecksum();
void setLayer2(uint8_t *dMAC, uint8_t *sMAC);
//void setLayer3(uint8_t *dIP, uint8_t *sIP);
void setEthFrame(uint8_t *dMAC, uint8_t *sMAC);


//typedef enum _eth_ip_checksum{
//    correct_checksum = 0,
//    wrong_checksum
//} eth_ip_checksum;

typedef struct _ethFrameStr{
    ///////////////////////////////////////////////////////////////////
    /// Support Data-link Layer (OSI-2nd-Layer) (Ethernet II Frame) ///
    ///////////////////////////////////////////////////////////////////

    uint8_t                 dstMAC[ETH_MAC_ADDR_SIZE];  // Destination MAC Address (6bytes)
    uint8_t                 srcMAC[ETH_MAC_ADDR_SIZE];  // Source MAC Address (6bytes)

    uint8_t                 VLANType[ETH_TYPE_SIZE];    // VLAN Type: 0x8100 (2bytes)

    uint8_t                 DEI : 1;                    // VLAN Tag DEI
    uint8_t                 PRI : 3;                    // VLAN Tag Priority
    uint8_t                 IDH : 4;                    // VLAN Tag ID High
    uint8_t                 IDL : 8;                    // VLAN Tag ID Low

    uint8_t                 ethType[ETH_TYPE_SIZE];     // EtherType (2bytes)

    ///////////////////////////////////////////////////////////////////////////
    /// Support Network Layer (OSI-3rd-Layer) (Internet Protocol Version 4) ///
    ///////////////////////////////////////////////////////////////////////////
//
//    uint8_t                 IHL : 4;                    // Internet Protocol Header Length (Unit: Word)
//    uint8_t                 IPV : 4;                    // Internet Protocol Version (4 or 6)
//    uint8_t                 ECN : 2;                    // Explicit Congestion Notification
//    uint8_t                 DSCP : 6;                   // Differentiated Services Code Point
//
//    uint8_t                 TotalLen[2];                // Total Packet Size (Unit: Byte)
//    uint8_t                 GroupID[2];                 // Fragmentation Group Identification
//    uint8_t                 fragInfo[2];                // Flags and Fragment Offset
//    uint8_t                 TTL;                        // Time-to-Live of Packet (Prevent routing-loop)
//    uint8_t                 Protocol;                   // Upper Layer Protocol Type (Example: ICMP[0x01] / IGMP[0x02] / TCP[0x06] / UDP[0x11])
//    uint8_t                 ICS[2];                     // IP Header Checksum Value
//
//    uint8_t                 srcIP[ETH_IP_ADDR_SIZE];    // Source IP Address (4bytes)
//    uint8_t                 dstIP[ETH_IP_ADDR_SIZE];    // Destination IP Address (4bytes)
//
//    uint8_t                 options;                    // IP Header Options (if IHL > 5)

    ///////////////////////////////////////////////////////////
    /// Support Transport Layer (OSI-4th-Layer) (TCP / UDP) ///
    ///////////////////////////////////////////////////////////

    uint8_t                 payload[ETH_MTU_SIZE - ETH_IP_HEADER_SIZE];

} ethFrameStr;

#endif /* G_ETHERNET_LIB_H_ */
