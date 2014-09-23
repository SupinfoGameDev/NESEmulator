#ifndef CORE_H
#define CORE_H

#include <cstdint> // uint8_t, uint16_t, uint32_t
#include <utility> // std::pair
#include <vector>  // std::vector

#include "cpu/bit_array.h"    // bit_array
#include "cpu/instructions.h" // 6502 opcodes

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

#ifndef DEBUG
#define DEBUG
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

int READ_MEMORY(Register pc);
int READ_MEMORY(int address);

} // CPU

constexpr int NEGATIVE_FLAG_ID  = 7;
constexpr int OVERFLOW_FLAG_ID  = 6;
constexpr int ALWAYS_1_FLAG_ID  = 5; // A ne normalement pas utiliser
constexpr int BREAK_FLAG_ID     = 4; // A ne normalement pas utiliser
constexpr int DECIMAL_FLAG_ID   = 3; // A ne normalement pas utiliser
constexpr int INTERRUPT_FLAG_ID = 2;
constexpr int ZERO_FLAG_ID      = 1;
constexpr int CARRY_FLAG_ID     = 0;

#endif // CORE_H
