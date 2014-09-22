#include "../include/core.h"

bit_array<8>  Registers::A  = 0x00;  // Accumulator Register
bit_array<8>  Registers::X  = 0x00;  // X Index Register
bit_array<8>  Registers::Y  = 0x00;  // Y Index Register
bit_array<8>  Registers::P  = 0x04;  // Processor Status Register
bit_array<16> Registers::PC = 0x00;  // Program Counter Register
bit_array<16> Registers::S  = 0x00;  // Stack Pointer Register

inline void SET_NEGATIVE(int operand)
{
    Registers::P[NEGATIVE_FLAG_ID] = (operand < 0) ? 1 : 0;
}

inline void SET_ZERO(int operand)
{
    Registers::P[ZERO_FLAG_ID] = (operand == 0) ? 1 : 0;
}

inline int READ_MEMORY(int address, int mode)
{
    int value; // = ...
    return value;
}

// MOV A, operand
void LDA(int operand, int mode)
{
    // Addressing mode
    switch (mode)
    {
        case AddressingMode::ZeroPage:
            operand = READ_MEMORY(operand, mode);
            break;
        case AddressingMode::Absolute:
            operand = READ_MEMORY(operand, mode);
            break;
    }
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
    Registers::A[7] = Registers::P[ZERO_FLAG_ID];
}

// MOV X, operand
void LDX(int operand, int mode)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::X = operand;
    Registers::X[7] = Registers::P[ZERO_FLAG_ID];
}

// MOV Y, operand
void LDY(int operand, int mode)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::Y = operand;
    Registers::Y[7] = Registers::P[ZERO_FLAG_ID];
}

// AND A, operand
void AND(int operand, int mode)
{
    operand &= Registers::A.to_number();
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
}

// XOR A, operand
void EOR(int operand, int mode)
{
    operand ^= Registers::A.to_number();
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
}

// SHL A, operand
void ASL(int operand, int mode)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = Registers::A.to_number() << operand;
}

// SHR A, operand
void LSR(int operand, int mode)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = Registers::A.to_number() >> operand;
}

// Transfer X to A
void TXA(int mode)
{
    Registers::A = Registers::X.to_number()
}

void TAX(int mode)
{
    Registers::X = Registers::A.to_number()
}

void TYA(int mode)
{
    Registers::A = Registers::Y.to_number()
}

void TAY(int mode)
{
    Registers::Y = Registers::A.to_number()
}

void TSX(int mode)
{
    Registers::X = Registers::S.to_number() & 0xff;
}

void TXS(int mode)
{
    Registers::S = Registers::X.to_number()
}

void STA(int operand, int mode)
{
    operand = Registers::A.to_number();
}

void STX(int operand, int mode)
{
    operand = Registers::X.to_number();
}

void STY(int operand, int mode)
{
    operand = Registers::Y.to_number();
}
