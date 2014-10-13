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

namespace nes { namespace cpu {
    
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

} // CPU
} // NES

const int NEGATIVE_FLAG_ID  = 7;
const int OVERFLOW_FLAG_ID  = 6;
const int ALWAYS_1_FLAG_ID  = 5; // A ne normalement pas utiliser
const int BREAK_FLAG_ID     = 4; // A ne normalement pas utiliser
const int DECIMAL_FLAG_ID   = 3; // A ne normalement pas utiliser
const int INTERRUPT_FLAG_ID = 2;
const int ZERO_FLAG_ID      = 1;
const int CARRY_FLAG_ID     = 0;

// Add reg, reg / reg, int / int, reg / int, int
template <typename FirstVal, typename SecondVal>
inline auto add(FirstVal val1, SecondVal val2) -> decltype(val1 + val2) {
    return val1 + val2;
}

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
#endif // DEBUG
#endif // CORE_H
