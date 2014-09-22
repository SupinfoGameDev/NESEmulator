#ifndef CORE_H
#define CORE_H

#include <cstdint>     // uint8_t, uint16_t, uint32_t
#include <utility>     // std::pair
#include <vector>      // std::vector
#include "bit_array.h" // bit_array

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

#ifndef DEBUG
#define DEBUG
#endif

#ifdef DEBUG
// Overload de << pour cout sur u8
#include <iostream> // std::cout, std::endl
std::ostream& operator<<(std::ostream& stream, const u8& i) {
    stream << static_cast<int>(i);
    return stream;
}
std::ostream& operator<<(std::ostream& stream, const u16& i) {
    stream << static_cast<int>(i);
    return stream;
}
std::ostream& operator<<(std::ostream& stream, const u32& i) {
    stream << static_cast<int>(i);
    return stream;
}
#endif

namespace CPU {
    
struct Registers
{
public:
    static bit_array<8>  A;
    static bit_array<8>  X;
    static bit_array<8>  Y;
    static bit_array<8>  P;
    static bit_array<16> PC;
    static bit_array<16> S;
private:
    virtual ~Registers() = 0;
};
}

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

constexpr int NEGATIVE_FLAG_ID  = 7;
constexpr int OVERFLOW_FLAG_ID  = 6;
constexpr int ALWAYS_1_FLAG_ID  = 5; // A ne normalement pas utiliser
constexpr int BREAK_FLAG_ID     = 4; // A ne normalement pas utiliser
constexpr int DECIMAL_FLAG_ID   = 3; // A ne normalement pas utiliser
constexpr int INTERRUPT_FLAG_ID = 2;
constexpr int ZERO_FLAG_ID      = 1;
constexpr int CARRY_FLAG_ID     = 0;

#endif
