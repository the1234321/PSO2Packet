#ifndef PSO2PACKET_COMMON_H
#define PSO2PACKET_COMMON_H

#ifdef _MSC_VER
#define PACKED( __Declaration__ )\
	__pragma( pack(push, 1) ) \
	__Declaration__ \
	__pragma( pack(pop) )
#else
#define PACKED(x) x __attribute__((packed, ms_struct))
#endif

#endif