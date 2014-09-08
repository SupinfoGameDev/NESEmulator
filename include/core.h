#ifndef TYPES_H
#define TYPES_H

#include <cstdint>     // uint8_t, uint16_t, uint32_t
#include "bit_array.h" // bit_array

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

namespace Registers
{
    static bit_array<8>  A  = 0x00;  // Accumulator Register
    static bit_array<8>  X  = 0x00;  // X Index Register
    static bit_array<8>  Y  = 0x00;  // Y Index Register
    static bit_array<8>  P  = 0x04;  // Processor Status Register
    static bit_array<16> PC = 0x00;  // Program Counter Register
    static bit_array<16> S  = 0x00;  // Stack Pointer Register
}

// Info *************************************************************
// 7ème bit = bit de signe => valeur max d'un registre 8 bits = 127 *
// Et valeur min d'un registre de 8 bits = -127 (127 + bits[7] à 1) *
// ******************************************************************

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

const int NEGATIVE_FLAG_ID  = 7;
const int OVERFLOW_FLAG_ID  = 6;
const int ALWAYS_1_FLAG_ID  = 5; // A ne normalement pas utiliser
const int BREAK_FLAG_ID     = 4; // A ne normalement pas utiliser
const int DECIMAL_FLAG_ID   = 3; // A ne normalement pas utiliser
const int INTERRUPT_FLAG_ID = 2;
const int ZERO_FLAG_ID      = 1;
const int CARRY_FLAG_ID     = 0;

// 6502 assembly opcodes

// Load ********************************************************
void LDA(int operand); // Charge la valeur de operand dans A   *
void LDX(int operand); // Charge la valeur de operand dans X   *
void LDY(int operand); // Charge la valeur de operand dans X   *
// Info ********************************************************
// Equivalents des opération de MOV
// *************************************************************

// Binary ops **************************************************
void AND(int operand); // Registers::A = operand & Register::A *
void EOR(int operand); // Registers::A = operand ^ Register::A *
void ORA(int operand); // Registers::A = operand | Register::A *
void ASL(int n);       // Registers::A = Registers::A << n     *
void LSR(int n);       // Registers::A = Registers::A >> n     *
// *************************************************************

// Transfers ***************************************************
void TXA(); // Transfère la valeur de X vers A                 *
void TAX(); // Transfère la valeur de A vers X                 *
void TYA(); // Transfère la valeur de Y vers A                 *
void TAY(); // Transfère la valeur de A vers Y                 *
void TSX(); // Transfère la valeur de S vers X (S : stack)     *
void TXS(); // Transfère la valeur de X vers S                 *
// *************************************************************

#endif
