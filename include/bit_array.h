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
	bit_array(const bit_array& copy) : bits(copy.bits)
	{
		set_bits();
	}
	bit_array(const std::array<int, size>& array) : bits(array)
	{
		set_bits();
	}
	void reset()
	{
		std::fill(bits.begin(), bits.end(), 0);
	}
	int to_number() const
	{
		return std::accumulate(bits.begin(), bits.end(), 0);
	}
	std::array<int, size> to_array() const
	{
		return bits;
	}
	int& operator[](int idx)
	{
		return bits.at(idx);
	}
	bit_array& operator=(const std::array<int, size>& list)
	{
		bits = list;
		set_bits();
		return *this;
	}
private:
	std::array<int, size> bits;
	void set_bits()
	{
		for (auto& bit : bits)
		{
			bit = !!bit;
		}
	}
};

#endif
