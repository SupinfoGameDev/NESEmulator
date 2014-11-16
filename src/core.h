#ifndef CORE_H
#define CORE_H

// std
#include <cstdint> // uint8_t, uint16_t, uint32_t
#include <utility> // std::pair
#include <vector>  // std::vector

// cpu
#include "cpu/bit_array.h"    // bit_array
#include "cpu/instructions.h" // 6502 opcodes

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

namespace nes {
    namespace cpu {
        namespace registers {
    
extern BitArray<8>  A;
extern BitArray<8>  X;
extern BitArray<8>  Y;
extern BitArray<8>  P;
extern BitArray<16> PC;
extern BitArray<16> S;

} // nes::cpu::registers
} // nes::cpu
} // nes

namespace constants {

enum Flags
{
    CarryFlag = 0,
    ZeroFlag,
    InterruptFlag,
    DecimalFlag, // A ne normalement pas utiliser
    BreakFlag,   // A ne normalement pas utiliser
    Always1Flag, // A ne normalement pas utiliser
    OverflowFlag,
    NegativeFlag
};

} // constants

#endif // CORE_H