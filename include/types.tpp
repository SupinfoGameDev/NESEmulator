bit_array::bit_array()
{
    std::fill(bits.begin(), bits.end(), 0);
}

bit_array::bit_array(const bit_array& copy)
    : bits(copy.bits)
{
    set_bits();
}

bit_array::bit_array(const std::array<int, size>& array)
    : bits(array)
{
    set_bits();
}

void bit_array::reset()
{
    std::fill(bits.begin(), bits.end(), 0);
}
    
int bit_array::to_number() const
{
    return std::accumulate(bits.begin(), bits.end(), 0);
}

std::array<int, size> bit_array::to_array() const
{
    return bits;
}
    
int& bit_array::operator[](int idx)
{
    return bits.at(idx);
}

bit_array& bit_array::operator=(const std::array<int, size>& list)
{
    bits = list;
    set_bits();
    return *this;
}

void bit_array::set_bits()
{
    for (auto& bit : bits)
    {
        bit = !!bit;
    }
}
