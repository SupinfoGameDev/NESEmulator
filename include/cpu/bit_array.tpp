template <int size>
bit_array<size>::bit_array()
{
    std::fill(bits.begin(), bits.end(), 0);
}
template <int size>
bit_array<size>::bit_array(const bit_array& copy)
    : bit_array(copy.to_number())
{
    set_bits();
}
template <int size>
bit_array<size>::bit_array(int number)
{
    set_number(number);
}
template <int size>
bit_array<size>::bit_array(const std::array<int, size>& array)
    : bits(array)
{
    set_bits();
}

template <int size>
void bit_array<size>::reset()
{
    std::fill(bits.begin(), bits.end(), 0);
}
template <int size>
int bit_array<size>::to_number() const
{
    std::array<int, size - 1> arr;
    for (unsigned i{}; i < arr.size(); i++)
    {
        arr[i] = bits[i + 1];
    }
    int sum = 0;
    for (unsigned i = arr.size(); i > 0; i--)
    {
        sum += arr[i - 1] << (arr.size() - i);
    }
    return (bits[0] == 0) ? sum : -sum;
}
template <int size>
std::array<int, size> bit_array<size>::to_array() const
{
    return bits;
}
template <int size>
int& bit_array<size>::operator[](int idx)
{
    return bits.at(idx);
}
template <int size>
bit_array<size>& bit_array<size>::operator=(int number)
{
    set_number(number);
    return *this;
}
template <int size>
bit_array<size>& bit_array<size>::operator=(const bit_array<size>& other)
{
    set_number(this->to_number() + other.to_number());
    return *this;
}
template <int size>
bit_array<size>& bit_array<size>::operator=(const std::array<int, size>& list)
{
    bits = list;
    set_bits();
    return *this;
}
template <int size>
bit_array<size> bit_array<size>::operator+(const int i)
{
    bit_array<size> b = this->to_number() + i;
    return b;
}
template <int size>
bit_array<size> bit_array<size>::operator+(const bit_array<size> b)
{
    return bit_array<size> { this->to_number() + b.to_number() };
    //return b;
}

template <int size>
void bit_array<size>::set_bits()
{
    for (auto& bit : bits)
    {
        bit = !!bit;
    }
}
template <int size>
void bit_array<size>::set_number(int number)
{
    int negative_bit = (number < 0);
    //number = abs(number) & 127; // & ou rabattre valeur à 127 / étendre sur autre registre ?
    number = number > 127 ? 127 : number; // overflow flag ?
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
