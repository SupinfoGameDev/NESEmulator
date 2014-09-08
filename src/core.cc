#include "../include/core.h"

inline void SET_NEGATIVE(int operand)
{
    Registers::P[NEGATIVE_FLAG_ID] = (operand < 0) ? 1 : 0;
}

inline void SET_ZERO(int operand)
{
    Registers::P[ZERO_FLAG_ID] = (operand == 0) ? 1 : 0;
}

// MOV A, operand
void LDA(int operand)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
    Registers::A[7] = Registers::P[ZERO_FLAG_ID]);
}

// MOV X, operand
void LDX(int operand)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
    Registers::A[7] = Registers::P[ZERO_FLAG_ID]);
}

// MOV Y, operand
void LDY(int operand)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
    Registers::A[7] = Registers::P[ZERO_FLAG_ID]);
}

// AND A, operand
void AND(int operand)
{
    operand &= Registers::A.to_number();
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
}

// XOR A, operand
void EOR(int operand)
{
    operand ^= Registers::A.to_number();
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
}
