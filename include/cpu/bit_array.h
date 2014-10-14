#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <algorithm> // std::fill, std::reverse
#include <array>     // std::array
#include <cmath>     // abs

template <int size = 8>
class bit_array {
public:
    bit_array(int number = 0);
    
    int& operator[](int idx);
    int to_number() const;
    std::array<int, size> to_array() const;
    
    bit_array& operator=(int number);
    bit_array operator+(const int i);
    bit_array operator+(const bit_array<size> b);
    
    // deleted functions
    bit_array(const bit_array& copy) = delete;
    bit_array& operator=(const bit_array& other) = delete;
    
private:
    std::array<int, size> bits;
    void set_bits();
    void set_number(int number);
};

#include "bit_array.tpp"

template <std::size_t size>
int operator+(const int i, const bit_array<size> b)
{
    return b.to_number() + i;
}

// Overload de << pour cout sur u8
#include <iostream> // std::cout, std::endl
template <int size>
std::ostream& operator<<(std::ostream& stream, const bit_array<size>& b) {
    stream << b.to_number();
    return stream;
}

#endif
