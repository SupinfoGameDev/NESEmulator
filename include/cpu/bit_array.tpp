template <int size>
BitArray<size>::BitArray(int number)
{
    set_number(number);
}

template <int size>
int BitArray<size>::to_number() const
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
std::array<int, size> BitArray<size>::to_array() const
{
    return bits;
}
template <int size>
int& BitArray<size>::operator[](int idx)
{
    return bits.at(idx);
}
template <int size>
BitArray<size>& BitArray<size>::operator=(int number)
{
    set_number(number);
    return *this;
}
template <int size>
BitArray<size> BitArray<size>::operator+(const int i)
{
    BitArray<size> b = this->to_number() + i;
    return b;
}
template <int size>
BitArray<size> BitArray<size>::operator+(const BitArray<size> b)
{
    return BitArray<size> { this->to_number() + b.to_number() };
    //return b;
}

template <int size>
void BitArray<size>::set_bits()
{
    for (auto& bit : bits)
    {
        bit = !!bit;
    }
}
template <int size>
void BitArray<size>::set_number(int number)
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
