#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <algorithm> // std::fill
#include <array>     // std::array
#include <numeric>   // std::accumulate
#include <string>    // std::to_string

template <int size = 8>
class bit_array {
public:
    bit_array()
    {
        std::fill(bits.begin(), bits.end(), 0);
    }
    bit_array(const bit_array& copy)
        : bits(copy.bits)
    {
        set_bits();
    }
    bit_array(int number)
    {
        std::fill(bits.begin(), bits.end(), 0);
        int i = 0;
        for (auto& b : bits)
        {
            b = !!(number & (1 << i));
            i++;
        }
        std::reverse(bits.begin(), bits.end());
    }
    bit_array(const std::array<int, size>& array)
        : bits(array)
    {
        set_bits();
    }
  
    inline void reset()
    {
        std::fill(bits.begin(), bits.end(), 0);
    }
    inline int to_number() const
    {
        int sum = 0;
        for (int i = bits.size(); i > 0; i--)
        {
            sum += bits[i-1] << (bits.size() - i);
        }
        return sum;
    }
    inline std::array<int, size> to_array() const
    {
        return bits;
    }
    inline int& operator[](int idx)
    {
        return bits.at(idx);
    }
    inline bit_array& operator=(int number)
    {
       	std::fill(bits.begin(), bits.end(), 0);
        int i = 0;
        for (auto& b : bits)
        {
            b = number & (1 << i);
            i++;
        }
        std::reverse(bits.begin(), bits.end());
        return *this;
    }
    inline bit_array& operator=(const std::array<int, size>& list)
    {
        bits = list;
        set_bits();
        return *this;
    }
private:
    std::array<int, size> bits;
    inline void set_bits()
    {
        for (auto& bit : bits)
        {
            bit = !!bit;
        }
    }
};

#endif
