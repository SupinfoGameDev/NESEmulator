#include "cpu.h"

using namespace nes::cpu;
using namespace constants;

std::bitset<8>  registers::A  { 0x00 };  // Accumulator Register
std::bitset<8>  registers::X  { 0x00 };  // X Index Register
std::bitset<8>  registers::Y  { 0x00 };  // Y Index Register
std::bitset<8>  registers::P  { 0x04 };  // Processor Status Register
std::bitset<16> registers::PC { 0x00 };  // Program Counter Register
std::bitset<16> registers::S  { 0x00 };  // Stack Pointer Register

namespace {

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

inline unsigned READ_MEMORY(const unsigned operand, const int mode)
{
    // Lecture de la ROM à l'adresse operand
    auto address = operand;
    switch (mode)
    {
        case AddressingMode::ZeroPage:
            break;
        case AddressingMode::Absolute:
            break;
        default:
            break;
    }
    return address;
}
} // namespace

// MOV A, operand
void LDA(const unsigned operand, const int mode)
{
    // Addressing mode
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
        default:
            break;
    }
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = operand;
}

// MOV X, operand
void LDX(const unsigned operand, const int mode)
{
    unsigned result{};
    switch (mode)
    {
        case AddressingMode::ZeroPage:
        case AddressingMode::Absolute:
            result = READ_MEMORY(operand, mode);
            break;
        default:
            break;
    }
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::X = operand;
}

// MOV Y, operand
void LDY(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
        default:
            break;
    }
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::Y = operand;
}

// AND A, operand
void AND(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
        default:
            break;
    }
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = to_number(registers::A) & operand;
}

// XOR A, operand
void EOR(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
        default:
            break;
    }
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = to_number(registers::A) ^ operand;
}

// SHL A, operand
void ASL(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
        default:
            break;
    }
    SET_NEGATIVE<8>(operand);
    SET_ZERO<8>(operand);
    registers::A = to_number(registers::A) << operand;
}

// SHR A, operand
void LSR(const unsigned operand, const int mode)
{
    switch (mode)
    {
        case AddressingMode::ZeroPage:
//            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
//            operand = READ_MEMORY(operand, mode);
            break;
        default:
            break;
    }
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
    registers::X = to_number(registers::S) & 0xff;
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
