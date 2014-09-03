#ifndef TYPES_H
#define TYPES_H

#include <cstdint> // uint8_t, uint16_t, uint32_t
#include "bit_array.h"

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

struct Registers
{
    virtual ~Registers() = 0;
    static bit_array<8>  A;  // Accumulator Register
    static bit_array<8>  X;  // X Index Register
    static bit_array<8>  Y;  // Y Index Register
    static bit_array<8>  P;  // Processor Status Register
    static bit_array<16> PC; // Program Counter Register
    static bit_array<16> S;  // Stack Pointer Register
};

bit_array<8>  Registers::A  = 0x00;
bit_array<8>  Registers::X  = 0x00;
bit_array<8>  Registers::Y  = 0x00;
bit_array<8>  Registers::P  = 0x04; // Registers::P[5] = 1
bit_array<16> Registers::PC = 0x00;
bit_array<16> Registers::S  = 0x00;

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
