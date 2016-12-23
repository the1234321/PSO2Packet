//PSO2 Packet Header

#ifndef PSO2PACKET_PACKET_HEADER_H
#define PSO2PACKET_PACKET_HEADER_H

#include <inttypes.h>
#include "../common/common.h"

//PSO2 Packet Header
//
//The header that precedes every packet.
PACKED
(
	struct PSO2PacketHeader
	{
		uint32_t size; //Total Packet Size, including the header
		uint8_t type; //Packet type, usually packets within the same type share some common uses
		uint8_t subtype; //Packet subtype
		uint_8 flags[0x2]; //Packet flags, second byte may be just for padding however (TODO)
	}
)

#endif