#ifndef TYPES_H
#define TYPES_H

#include <array>

#define to_u8(x) ((int)(x & 255))

typedef unsigned char u8; // Entier non signé sur 8 bits

template <int size = 8>
class BitArray
{
    public:
        BitArray();
        std::array<int, size> to_array() { return bits; }
        int& operator[](int idx) { return bits[idx]; }
        
    private:
        std::array<int, size> bits;
};

typedef BitArray bit_array;

#endif
