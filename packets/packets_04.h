// Character Movement/Animation Related

#ifndef PSO2PACKET_PACKET_04_H
#define PSO2PACKET_PACKET_04_H

#include <inttypes.h>
#include "../common/common.h"

//Damage Packet
//04.0fs,04.52s
//Damage Info Packet
//
//Damage Types:
// 0x1 = Just Attack
// 0x2 = ?
// 0x4 = Misc. (Healing, Lava, etc...)
// 0x8 = Damage
// 0x10 = Multi-hit? (Infinity Fire, One Point have this after the first hit)
// 0x20 = Misc.2 (Zanverse uses this)
// 0x40 = Critical
// 0x80 = ?
PACKED
(
	struct PSO2PacketDamage
	{
		uint32_t playerID; //Arks ID for active user
		uint8_t unk1[8]; //TODO
		uint32_t targetID; //Target ID, character ID
		uint8_t unk2[6]; //TODO
		uint16_t instanceID; //Current Instance ID
		uint32_t sourceID; //Source ID, character ID
		uint8_t unk3[8]; //TODO
		uint32_t atkID; //Attack/Animation ID, unique to each move
		int32_t value; //Actual damage/healing value, can be positive or negative
		uint8_t unk4[16]; //TODO
		uint8_t flags; //Damage Type, refer to description
		uint8_t unk5[11]; //TODO
	} 
)

#endif