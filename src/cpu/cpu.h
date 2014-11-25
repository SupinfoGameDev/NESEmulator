#ifndef NESEMU_CPU_H
#define NESEMU_CPU_H

#include <bitset>    // std::bitset
#include <cstdint>   // uint8_t, uint16_t, uint32_t

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

namespace nes {
    namespace cpu {
        namespace registers {
    
extern std::bitset<8>  A;
extern std::bitset<8>  X;
extern std::bitset<8>  Y;
extern std::bitset<8>  P;
extern std::bitset<16> PC;
extern std::bitset<16> S;

} // nes::cpu::registers
} // nes::cpu
} // nes

namespace constants {

enum Flags
{
    CarryFlag = 0,
    ZeroFlag,
    InterruptFlag,
    DecimalFlag,   // A ne normalement pas utiliser
    BreakFlag,     // A ne normalement pas utiliser
    Always1Flag,   // A ne normalement pas utiliser
    OverflowFlag,
    NegativeFlag
};

} // constants

enum AddressingMode
{
    Absolute = 1,        // $ (little-endiant) -> ex: AD A0 16 => LDA $16A0
    Accumulator,         // Implied addressing mode only for A register -> ex: LSR
    Immediate,           // #$
    Implied,             // When there's no operand -> ex: TAX
    Indexed,
    Indirect,
    PostIndexedIndirect,
    PreIndexed,
    Relative,
    ZeroPage,            // $
    ZeroPageIndexed
};

// Storage  ***************************************
void LDA(const unsigned operand, const int mode); // A = operand   *
void LDX(const unsigned operand, const int mode); // X = operand   *
void LDY(const unsigned operand, const int mode); // Y = operand   *
void STA(const unsigned operand, const int mode); // operand = A   *
void STX(const unsigned operand, const int mode); // operand = X   *
void STY(const unsigned operand, const int mode); // operand = Y   *
void TAX(); // Transfère la valeur de A vers X    *
void TAY(); // Transfère la valeur de A vers Y    *
void TSX(); // Transfère la valeur de S vers X    *
void TXA(); // Transfère la valeur de S vers A    *
void TXS(); // Transfère la valeur de X vers S    *
void TYA(); // Transfère la valeur de Y vers A    *
//  ***********************************************

// Math  ******************************************
//                                                *
//  ***********************************************

// Bitvise  ***************************************
void AND(const unsigned operand, const int mode); // A &= operand  *
void ASL(const unsigned operand, const int mode); // A <<= operand *
//                                                *
void EOR(const unsigned operand, const int mode); // A ^= operand  *
void LSR(const unsigned operand, const int mode); // A >>= operand *
void ORA(const unsigned operand, const int mode); // A |= operand  *
//                                                *
//                                                *
//  ***********************************************

// Note  ******************************************
// ST[A|X|Y] = "Store [register] in memory"       *
//  ***********************************************

#endif // NESEMU_CPU_H
