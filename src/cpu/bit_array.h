#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <algorithm> // std::fill, std::reverse
#include <array>     // std::array
#include <bitset>    // std::bitset
#include <cmath>     // abs

#include "../tools/NonCopyable.h"

template <size_t size>
int to_number(const std::bitset<size>& bits)
{
    static_assert(size == 8 || size == 16, "bad size for register");
    const unsigned flag = (size == 8) ? 0b1000'0000 : 0b1000'0000'0000'0000;
    auto num = bits.to_ulong() ^ flag;
    return bits[0] ? -num : num;
}

template <int size = 8>
class BitArray : public NonCopyable
{
typedef typename std::array<int, size>::size_type array_size;
public:
    BitArray(int number);
	    
    int& operator[](unsigned long idx);
    int to_number() const;
    std::array<int, size> to_array() const;
    
    BitArray& operator=(int number);
    BitArray operator+(const int i);
    BitArray operator+(const BitArray<size> b);
    
private:
    std::array<int, size> _bits;
    void set_bits();
    void set_number(int number);
};

#include "bit_array.tpp"

template <std::size_t size>
int operator+(const int i, const BitArray<size>& b)
{
    return b.to_number() + i;
}

// Overload de << pour cout
#include <iostream> // std::cout, std::endl
template <int size>
std::ostream& operator<<(std::ostream& stream, const BitArray<size>& b) {
    stream << b.to_number();
    return stream;
}

#endif
