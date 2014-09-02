#ifndef TYPES_H
#define TYPES_H

#include <algorithm> // std::fill
#include <array>     // std::array
#include <cstdint>   // uint8_t, uint16_t, uint32_t
#include <numeric>   // std::accumulate
#include <string>    // std::to_string

typedef uint8_t  u8;  // Entier non signé sur 8 bits
typedef uint16_t u16; // Entier non signé sur 16 bits
typedef uint32_t u32; // Entier non signé sur 32 bits

#define to_u8(x)  ((int)(x & 0xff))
#define to_u16(x) ((int)(x & 0xffff))

int from_binary(int bin);

template <int size = 8>
class bit_array {
public:
    bit_array();
    bit_array(const bit_array& copy);
    bit_array(const std::array<int, size>& array);
    
    int to_number() const;
    std::array<int, size> to_array() const;
    
    int& operator[](int idx);
    bit_array& operator=(const std::array<int, size>& list);
    
private:
    std::array<int, size> bits;
    
    void set_bits();
};

typedef bit_array<8> byte;

#endif
