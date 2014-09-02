#include "../include/types.h"

BitArray::BitArray()
{
    std::fill(bits.begin(), bits.end(), 0);
}

std::array<int, size> BitArray::to_array()
{
    return bits;
}

int& BitArray::operator[](int idx)
{
    return bits[idx];
}
