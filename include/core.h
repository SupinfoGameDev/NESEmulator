#ifndef CORE_H
#define CORE_H

#include <cstdint>     // uint8_t, uint16_t, uint32_t
#include <utility>     // std::pair
#include <vector>      // std::vector
#include "bit_array.h" // bit_array

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

#ifndef DEBUG
#define DEBUG
#endif

#ifdef DEBUG
// Overload de << pour cout sur u8
#include <iostream> // std::cout, std::endl
std::ostream& operator<<(std::ostream& stream, const u8& i)
{
    stream << (int) i;
    return stream;
}
#endif

namespace CPU {
    
struct Registers
{
public:
    static bit_array<8>  A;
    static bit_array<8>  X;
    static bit_array<8>  Y;
    static bit_array<8>  P;
    static bit_array<16> PC;
    static bit_array<16> S;
private:
    virtual ~Registers() = 0;
};

// Registres ********************************************************
// Accumulator Register       A    1                                *
// X Index Register           X    1                                *
// Y Index Register           Y    1                                *
// Processor Status Register  P    1                                *
// Program Counter Register   PC   2                                *
// Stack Pointer Register     S    2                                *
// ******************************************************************

// Info *************************************************************
// 7ème bit = bit de signe => valeur max d'un registre 8 bits = 127 *
// Et valeur min d'un registre de 8 bits = -127 (127 + bits[7] à 1) *
// ******************************************************************
}

/*
=====================
|  P Register bits: |
=====================
7 - N - Negative Flag  => Vaut 1 si le résultat de toute opération sur A, X ou Y est négatif, 0 sinon
6 - V - Overflow Flag  => vaut 1 si tout résultat arithmétique est supérieur 127 ou inférieur à -127
5 - 1 - Always 1 Flag  => Vaut toujours 1
4 - B - Break Flag     => Vaut 1 si le programme exécute un BRK. A considérer comme toujours égal à 0
3 - D - Decimal Flag   => La NES n'utilise pas de nombres décimaux. A considérer comme toujours égal à 0
2 - I - Interrupt Flag => Empêche les interruptions si à 1
1 - Z - Zero Flag      => Vaut 1 si une opération arithmétique retourne 0
0 - C - Carry Flag     =>
*/

constexpr int NEGATIVE_FLAG_ID  = 7;
constexpr int OVERFLOW_FLAG_ID  = 6;
constexpr int ALWAYS_1_FLAG_ID  = 5; // A ne normalement pas utiliser
constexpr int BREAK_FLAG_ID     = 4; // A ne normalement pas utiliser
constexpr int DECIMAL_FLAG_ID   = 3; // A ne normalement pas utiliser
constexpr int INTERRUPT_FLAG_ID = 2;
constexpr int ZERO_FLAG_ID      = 1;
constexpr int CARRY_FLAG_ID     = 0;

enum AddressingMode
{
    Absolute = 1,
    Accumulator,
    Immediate,
    Implied,
    Indexed,
    Indirect,
    PostIndexedIndirect,
    PreIndexed,
    Relative,
    ZeroPage,
    ZeroPageIndexed
};

// 6502 assembly opcodes
/*
Storage
LDA - Load A with M
LDX - Load X with M
LDY - Load Y with M
STA - Store A in M
STX - Store X in M
STY - Store Y in M
TAX - Transfer A to X
TAY - Transfer A to Y
TSX - Transfer Stack Pointer to X
TXA - Transfer X to A
TXS - Transfer X to Stack Pointer
TYA - Transfer Y to A

Math
ADC - Add M to A with Carry
DEC - Decrement M by One
DEX - Decrement X by One
DEY - Decrement Y by One
INC - Increment M by One
INX - Increment X by One
INY - Increment Y by One
SBC - Subtract M from A with Borrow

Bitwise
AND - "AND" M with A
ASL - Shift Left One Bit (M or A)
BIT - Test Bits in M with A
EOR - "Exclusive-Or" M with A
LSR - Shift Right One Bit (M or A)
ORA - "OR" M with A
ROL - Rotate One Bit Left (M or A)
ROR - Rotate One Bit Right (M or A)

Branch
BCC - Branch on Carry Clear
BCS - Branch on Carry Set
BEQ - Branch on Result Zero
BMI - Branch on Result Minus
BNE - Branch on Result not Zero
BPL - Branch on Result Plus
BVC - Branch on Overflow Clear
BVS - Branch on Overflow Set

Jump
JMP - Jump to Location
JSR - Jump to Location Save Return Address
RTI - Return from Interrupt
RTS - Return from Subroutine

Registers
CLC - Clear Carry Flag
CLD - Clear Decimal Mode
CLI - Clear interrupt Disable Bit
CLV - Clear Overflow Flag
CMP - Compare M and A
CPX - Compare M and X
CPY - Compare M and Y
SEC - Set Carry Flag
SED - Set Decimal Mode
SEI - Set Interrupt Disable Status

Stack
PHA - Push A on Stack
PHP - Push Processor Status on Stack
PLA - Pull A from Stack
PLP - Pull Processor Status from Stack

System
BRK - Force Break
NOP - No Operation
*/

// Storage *******************************************************************
void LDA(int operand, int mode = AddressingMode::Immediate); // A = operand  *
void LDX(int operand, int mode = AddressingMode::Immediate); // X = operand  *
void LDY(int operand, int mode = AddressingMode::Immediate); // Y = operand  *
void STA(int operand, int mode = AddressingMode::Immediate); // operand = A  *
void STX(int operand, int mode = AddressingMode::Immediate); // operand = X  *
void STY(int operand, int mode = AddressingMode::Immediate); // operand = Y  *
void TAX(); // Transfère la valeur de A vers X                               *
void TAY(); // Transfère la valeur de A vers Y                               *
void TSX(); // Transfère la valeur de S vers X                               *
void TXA(); // Transfère la valeur de S vers A                               *
void TXS(); // Transfère la valeur de X vers S                               *
void TYA(); // Transfère la valeur de Y vers A                               *
// ***************************************************************************

// Math **********************************************************************
//                                                                           *
// ***************************************************************************

// Bitvise *******************************************************************
void AND(int operand, int mode = AddressingMode::Immediate); // A &= operand *
void ASL(int n, int mode = AddressingMode::Immediate);       // A <<= n      *
//                                                                           *
void EOR(int operand, int mode = AddressingMode::Immediate); // A ^= operand *
void LSR(int n, int mode = AddressingMode::Immediate);       // A >>= n      *
void ORA(int operand, int mode = AddressingMode::Immediate); // A |= operand *
//                                                                           *
//                                                                           *
// ***************************************************************************

// Note ********************************************************
// ST[A|X|Y] = "Store [register] in memory"                    *
// *************************************************************

#endif
