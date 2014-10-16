#ifndef NESEMU_INSTRUCTIONS_H
#define NESEMU_INSTRUCTIONS_H

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

//int READ_MEMORY(Register pc);
int READ_MEMORY(int address);

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
