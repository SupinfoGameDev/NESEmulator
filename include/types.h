#ifndef TYPES_H
#define TYPES_H

#include <cstdint> // uint8_t, uint16_t, uint32_t
#include "bit_array.h"

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

namespace Registers
{
    bit_array<8>  A  = 0x00;  // Accumulator Register
    bit_array<8>  X  = 0x00;  // X Index Register
    bit_array<8>  Y  = 0x00;  // Y Index Register
    bit_array<8>  P  = 0x04;  // Processor Status Register
    bit_array<16> PC = 0x00;  // Program Counter Register
    bit_array<16> S  = 0x00;  // Stack Pointer Register
};

/*
P Register bits:
    7 - N - Negative Flag
    6 - V - Overflow Flag
    5 - 1 - Always 1 Flag
    4 - B - Break Flag
    3 - D - Decimal Flag
    2 - I - Interrupt Flag
    1 - Z - Zero Flag
    0 - C - Carry Flag
*/

#endif
