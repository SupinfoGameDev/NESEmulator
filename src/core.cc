#include "../include/core.h"

inline void SET_NEGATIVE(int& operand)
{
    if (operand < 0)
    {
        Registers::P[NEGATIVE_FLAG_ID] = 1;
        operand = -operand;
        return;
    }
    Registers::P[NEGATIVE_FLAG_ID] = 0;
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
}

// MOV X, operand
void LDA(int operand)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
}

// MOV Y, operand
void LDA(int operand)
{
    SET_NEGATIVE(operand);
    SET_ZERO(operand);
    Registers::A = operand;
}

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