# What is this?

A repository to store header files that define the various Phantasy Star Online 2 Packet types and structures with a strict format for documentation generation.

# Why does this exist?

To have a single place to store PSO2 Packet information for use with various related projects (Proxies, Private Server projects, etc...).

# What is the current status?

Currently we're still trying to retrieve a lot of packet information.

# How can I help?

Make a PR!

TODO: Packet analysis guide.

# Files

./packetdef.h
- To be included in projects
- References all other packet files

./packets/packet_header.h
- Defines the Packet Header structure
- Common to all packets

./packets/packet_XX.h (except header)
- XX is a hexadecimal number representing the packet type
- A specific file defines all packets under the XX packet type

# Packet File Spec

Contributors, please follow the specification so that documentation can be generated automatically.

Each ./packet/packet_XX.h file follows a template:

```
// Packet Type related information goes here

#ifndef PSO2PACKET_PACKET_XX_H
#define PSO2PACKET_PACKET_XX_H

#include <inttypes.h>
#include "../common/common.h"

//Packet Title
//XX.YY,XX.ZZ
//Packet Description Line 1
//Packet Description Line 2
//Packet Description Line 3
PACKED
(
	struct PSO2PacketSomething
	{
	    uint8_t someVariable[0x8]; //Description of someVariable
	    uint8_t unk1[0x8]; //TODO
	} 
)

//Packet Title 2
//XX.WW
//Packet Description Line 1
PACKED
(
	struct PSO2PacketSomethingElse
	{
	    uint8_t someVariable; //Description of someVariable
	    void* data; //someVariable;Description of data
	    uint32_t anotherVariable; //Description of anothervariable
	} 
)

#endif
```

Each section is shown separately below with a more detailed description underneath.

```
// Packet Type related information goes here
```
Packets within a specific type tend to have some common factors, this would defined in the first comment of the file.
```
#ifndef PSO2PACKET_PACKET_XX_H
#define PSO2PACKET_PACKET_XX_H
...
#endif
```
Start and end the file with a ifndef define/endif to make sure it can be imported without causing any duplicate definition issues, replacing XX with the packet type.
```
#include <inttypes.h>
#include "../common/common.h"
...
PACKED(
    ...
)
```
<inttypes.h> allows for portable type definitions, please stick to using types defined in this file, that is:
> int8_t
uint8_t
int16_t
uint16_t
int32_t
uint32_t
int64_t
uint64_t

common.h contains definitions for the PACKED macro, which simply define the structures as packed (to avoid structure alignment issues).

```
//Packet Title
//XX.YY,XX.ZZ
//Packet Description Line 1
//Packet Description Line 2
//Packet Description Line 3
```

For automatic documentation generation, the comments before each packet must adhere to the above structure. 
- The first line is always the packet title (a short descriptor for the packet).
- The second line is a comma delimited list of full packet IDs the structure is found in (e.g. 04.52,04.0f)
- The 3rd and all following lines are the description, where each new line is a new line in the documentation

```
PACKED
(
    struct PSO2PacketSomething
    {
        uint8_t someVariable[0x8]; //Description of someVariable
        uint8_t unk1[0x8]; //TODO
    } 
)
```
- All packets are defined as a structure with the name always preceded by PSO2Packet (this is a style guideline). 
- All packets should be wrapped in the PACKED macro, for ease of use in actual code
- Types are all portable types defined in inttypes.h
- Arrays should always have size defined in hex (style guideline)
- Each variable must have a description after it, if the variable is unknown see the next point
- Unknown variables should be marked as unk followed by an increasing integer counter (starting the count at 1), the comment should be //TODO
- Unknown sections should be treated as uint8_t arrays (byte arrays)

```
PACKED
(
	struct PSO2PacketSomethingElse
	{
	    uint8_t someVariable; //Description of someVariable
	    void* data; //someVariable;Description of data
	    uint32_t anotherVariable; //Description of anothervariable
	} 
)
```
- If a packet has some data of variable width, it should be marked as a void*, and the comment should follow the format of: ```//Variable Tracking Length Of Data; Description```
-- Spaces before the description will be stripped off
-- If no information about the length is available in this packet, leave the section blank ```//;Description``` or ```//;TODO``` if information is lacking
