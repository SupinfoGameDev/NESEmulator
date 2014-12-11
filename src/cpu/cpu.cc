#include <iostream>
#include "cpu.h"

using namespace constants;

namespace registers
{
    std::bitset<8>  A  { 0x00 };  // Accumulator Register
    std::bitset<8>  X  { 0x00 };  // X Index Register
    std::bitset<8>  Y  { 0x00 };  // Y Index Register
    std::bitset<8>  P  { 0x04 };  // Processor Status Register
    std::bitset<8>  S  { 0x00 };  // Stack Pointer Register
    std::bitset<16> PC { 0x00 };  // Program Counter Register
}

template <size_t size>
u32 to_number(const std::bitset<size>& bits)
{
    static_assert(size == 8 || size == 16, "bad register size");
    return bits.to_ulong();
}

template <size_t size>
u32 operator+(const unsigned i, const std::bitset<size>& b)
{
    static_assert(size == 8 || size == 16, "bad register size");
    return to_number(b) + i;
}

template <size_t size>
inline void SET_NEGATIVE(const std::bitset<size>& operand)
{
    static_assert(size == 8 || size == 16, "bad register size");
    registers::P[Flags::NegativeFlag] = operand[0];
}

template <size_t size>
inline void SET_ZERO(const std::bitset<size>& operand)
{
    static_assert(size == 8 || size == 16, "bad register size");
    registers::P[Flags::ZeroFlag] = operand[0];
}

inline u16 READ_MEMORY(const u16 operand, const unsigned mode)
{
    // Lecture de la ROM à l'adresse operand
    (void) operand;
    (void) mode;
    unsigned result{};
    switch (mode)
    {
        case AddressingMode::ZeroPage:
        case AddressingMode::Absolute:
            break;
        default:
            break;
    }
    return result;
}

// MOV A, operand
void LDA(const u16 operand, const unsigned mode)
{
    const unsigned result = READ_MEMORY(operand, mode);
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = operand;
}

// MOV X, operand
void LDX(const u16 operand, const unsigned mode)
{
    const unsigned result = READ_MEMORY(operand, mode);
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::X = operand;
}

// MOV Y, operand
void LDY(const u16 operand, const unsigned mode)
{
    const unsigned result = READ_MEMORY(operand, mode);
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::Y = operand;
}

// AND A, operand
void AND(const u16 operand, const unsigned mode)
{
    const unsigned result = READ_MEMORY(operand, mode);
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = to_number(registers::A) & operand;
}

// XOR A, operand
void EOR(const unsigned operand, const unsigned mode)
{
    const unsigned result = READ_MEMORY(operand, mode);
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = to_number(registers::A) ^ operand;
}

// SHL A, operand
void ASL(const u16 operand, const unsigned mode)
{
    const unsigned result = READ_MEMORY(operand, mode);
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = to_number(registers::A) << operand;
}

// SHR A, operand
void LSR(const u16 operand, const unsigned mode)
{
    const unsigned result = READ_MEMORY(operand, mode);
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = to_number(registers::A) >> operand;
}

// Transfer X to A
void TXA()
{
    registers::A = registers::X;
}

void TAX()
{
    registers::X = registers::A;
}

void TYA()
{
    registers::A = registers::Y;
}

void TAY()
{
    registers::Y = registers::A;
}

void TSX()
{
    registers::X = to_number(registers::S);
}

void TXS()
{
    registers::S = to_number(registers::X);
}
/*
void STA(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
    }
    operand = registers::A.to_number();
}

void STX(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
    }
    operand = registers::X.to_number();
    
}

void STY(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
    }
    operand = registers::Y.to_number();
}*/
