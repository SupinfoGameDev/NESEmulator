#include "../include/types.h"

inline int from_binary(int bin)
{
    int sum = 0;
    std::string base = std::to_string(bin);
    for (int i{}; i < base.size(); i++)
    {
    	sum += (int)(base[i] - '0') * 1 << i;
    }
    return sum;
}
