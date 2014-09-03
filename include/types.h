#ifndef TYPES_H
#define TYPES_H

#include <cstdint> // uint8_t, uint16_t, uint32_t

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

#include "bit_array.h"
typedef bit_array<8> byte;

inline u8  to_u8(int x)  { return (x & 0x00ff); }
inline u16 to_u16(int x) { return (x & 0xffff); }

#endif
