#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

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

// Custom  ****************************************
template <int N>
void MOV(Register<N>& reg, int value) {
    reg = value;
}

// Storage  ***************************************
void LDA(int operand, int mode); // A = operand   *
void LDX(int operand, int mode); // X = operand   *
void LDY(int operand, int mode); // Y = operand   *
void STA(int operand, int mode); // operand = A   *
void STX(int operand, int mode); // operand = X   *
void STY(int operand, int mode); // operand = Y   *
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
void AND(int operand, int mode); // A &= operand  *
void ASL(int operand, int mode); // A <<= operand *
//                                                *
void EOR(int operand, int mode); // A ^= operand  *
void LSR(int operand, int mode); // A >>= operand *
void ORA(int operand, int mode); // A |= operand  *
//                                                *
//                                                *
//  ***********************************************

// Note  ******************************************
// ST[A|X|Y] = "Store [register] in memory"       *
//  ***********************************************

#endif
