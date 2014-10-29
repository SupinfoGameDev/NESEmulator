#include "../include/core.h"

using namespace nes::cpu;
using namespace constants;

BitArray<8>  registers::A  { 0x00 };  // Accumulator Register
BitArray<8>  registers::X  { 0x00 };  // X Index Register
BitArray<8>  registers::Y  { 0x00 };  // Y Index Register
BitArray<8>  registers::P  { 0x04 };  // Processor Status Register
BitArray<16> registers::PC { 0x00 };  // Program Counter Register
BitArray<16> registers::S  { 0x00 };  // Stack Pointer Register

inline void SET_NEGATIVE(int operand)
{
    registers::P[Flags::NegativeFlag] = (operand < 0) ? 1 : 0;
}

inline void SET_ZERO(int operand)
{
    registers::P[Flags::ZeroFlag] = (operand == 0) ? 1 : 0;
}

// MOV A, operand
void LDA(int operand, int mode)
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
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    registers::A = operand;
    registers::A[7] = registers::P[Flags::ZeroFlag];
}

// MOV X, operand
void LDX(int operand, int mode)
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
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    registers::X = operand;
    registers::X[7] = registers::P[Flags::ZeroFlag];
}

// MOV Y, operand
void LDY(int operand, int mode)
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
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    registers::Y = operand;
    registers::Y[7] = registers::P[Flags::ZeroFlag];
}

// AND A, operand
void AND(int operand, int mode)
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
    operand &= registers::A.to_number();
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    registers::A = operand;
}

// XOR A, operand
void EOR(int operand, int mode)
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
    operand ^= registers::A.to_number();
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    registers::A = operand;
}

// SHL A, operand
void ASL(int operand, int mode)
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
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    registers::A = registers::A.to_number() << operand;
}

// SHR A, operand
void LSR(int operand, int mode)
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
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    registers::A = registers::A.to_number() >> operand;
}

// Transfer X to A
void TXA()
{
    
    registers::A = registers::X.to_number();
}

void TAX()
{
    registers::X = registers::A.to_number();
}

void TYA()
{
    registers::A = registers::Y.to_number();
}

void TAY()
{
    registers::Y = registers::A.to_number();
}

void TSX()
{
    registers::X = registers::S.to_number() & 0xff;
}

void TXS()
{
    registers::S = registers::X.to_number();
}
/*
void STA(int operand, int mode)
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

void STX(int operand, int mode)
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

void STY(int operand, int mode)
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
