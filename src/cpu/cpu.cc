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
inline void SET_NEGATIVE(const unsigned operand) {
    static_assert(size == 8 || size == 16, "bad register size");
    auto condition = (size == 8) ? (operand & 0x80) : (operand & 0x8000);
    registers::P[Flags::NegativeFlag] = condition ? 1 : 0;
}

template <size_t size>
inline void SET_NEGATIVE(const std::bitset<size>& operand) {
    static_assert(size == 8 || size == 16, "bad register size");
    registers::P[Flags::NegativeFlag] = operand[0];
}

inline void SET_ZERO(const unsigned operand) {
    registers::P[Flags::ZeroFlag] = (operand == 0) ? 1 : 0;
}

template <size_t size>
inline void SET_ZERO(const std::bitset<size>& operand) {
    registers::P[Flags::ZeroFlag] = operand[0];
}

inline void READ_MEMORY(unsigned operand, int mode) {
    // Lecture de la ROM à l'adresse operand
}
} // namespace

// MOV A, operand
void LDA(unsigned operand, int mode)
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
void LDX(unsigned operand, int mode)
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
    registers::X = operand;
}

// MOV Y, operand
void LDY(unsigned operand, int mode)
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
void AND(unsigned operand, int mode)
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
void EOR(unsigned operand, int mode)
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
void ASL(unsigned operand, int mode)
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
void LSR(unsigned operand, int mode)
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
void STA(unsigned operand, int mode)
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

void STX(unsigned operand, int mode)
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

void STY(unsigned operand, int mode)
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
