#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <algorithm> // std::fill, std::reverse
#include <array>     // std::array
#include <cmath>     // abs

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
        set_number(number);
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
        std::array<int, size - 1> arr;
		int i{};
        for (auto& bit : arr)
        {
            bit = bits[i+1];
			i++;
        }
        int sum = 0;
        for (auto i = arr.size(); i > 0; i--)
        {
            sum += arr[i - 1] << (arr.size() - i);
        }
        return (bits[0] == 0) ? sum : -sum;
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
        set_number(number);
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
    inline void set_number(int number)
    {
        int negative_bit = (number < 0);
        number = abs(number) & 127; // & ou rabattre valeur à 127 / étendre sur autre registre ?
        std::fill(bits.begin(), bits.end(), 0);
        int i = 0;
        for (auto& b : bits)
        {
            b = !!(number & (1 << i));
            i++;
        }
        std::reverse(bits.begin(), bits.end());
        bits[0] = negative_bit;
    }
};

#endif
