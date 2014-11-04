#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <algorithm> // std::fill, std::reverse
#include <array>     // std::array
#include <cmath>     // abs

#include "../../tools/NonCopyable.h"

template <int size = 8>
class BitArray : public NonCopyable
{
typedef typename std::array<int, size>::size_type array_size;
public:
    BitArray(int number);
	    
    int& operator[](int idx);
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
