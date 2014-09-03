#ifndef TYPES_H
#define TYPES_H

#include <cstdint> // uint8_t, uint16_t, uint32_t

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

#include "bit_array.h"
typedef bit_array<8> byte;

struct Registers
{
    virtual Registers() = 0;
    static bit_array<8>  A;  // Accumulator Register
    static bit_array<8>  X;  // X Index Register
    static bit_array<8>  Y;  // Y Index Register
    static bit_array<8>  P;  // Processor Status Register
    static bit_array<16> PC; // Program Counter Register
    static bit_array<16> S;  // Stack Pointer Register
};

bit_array<8>  Registers::A  = 0;
bit_array<8>  Registers::X  = 0;
bit_array<8>  Registers::Y  = 0;
bit_array<8>  Registers::P  = 0;
bit_array<16> Registers::PC = 0;
bit_array<16> Registers::S  = 0;

#endif
