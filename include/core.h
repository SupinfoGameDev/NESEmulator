#ifndef CORE_H
#define CORE_H

#include <cstdint> // uint8_t, uint16_t, uint32_t
#include <utility> // std::pair
#include <type_traits>
#include <vector>  // std::vector

#include "cpu/bit_array.h"    // bit_array
#include "cpu/instructions.h" // 6502 opcodes

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

namespace nes {
    namespace cpu {
        namespace registers {
    
extern BitArray<8>  A;
extern BitArray<8>  X;
extern BitArray<8>  Y;
extern BitArray<8>  P;
extern BitArray<16> PC;
extern BitArray<16> S;

} } } // nes::cpu::registers

// Add reg, reg / reg, int / int, reg / int, int
template <typename T>
inline T add(const T& val1, const T& val2))
{
    return val1 + val2;
}
[[deprecated("unsafe")]]
template <typename FirstVal, typename SecondVal>
inline auto add(const FirstVal& val1, const SecondVal& val2)
    -> decltype(val1 + val2)
{
    return val1 + val2;
}

namespace constants {

enum Flags
{
    CarryFlag = 0,
    ZeroFlag,
    InterruptFlag,
    DecimalFlag, // A ne normalement pas utiliser
    BreakFlag,   // A ne normalement pas utiliser
    Always1Flag, // A ne normalement pas utiliser
    OverflowFlag,
    NegativeFlag
};

} // constants

#ifdef DEBUG
// Overload de << pour cout sur u8
#include <iostream> // std::cout, std::endl
/*std::ostream& operator<<(std::ostream& stream, const u8& i) {
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
}*/
#endif // DEBUG
#endif // CORE_H
