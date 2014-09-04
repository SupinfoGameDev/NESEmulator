#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "core.h" // Registers

// TODO - Mappings opcode <=> fonction

namespace Cache
{
    
}

template <int size>
inline void mov(bit_array<size>& reg, int number)
{
    if (number < 0)
    {
        number = -number;
    }
    Registers::P[NEGATIVE_FLAG_ID] = (number < 0)  ? 1 : 0;
    Registers::P[ZERO_FLAG_ID]     = (number == 0) ? 1 : 0;
    reg = number;
}

template <int size1, int size2>
inline void mov(bit_array<size1>& dest, const bit_array<size2>& reg)
{
    int number = reg.to_number();
    Registers::P[ZERO_FLAG_ID] = (number == 0) ? 1 : 0;
    dest = number;
}

#endif
