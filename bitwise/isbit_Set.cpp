#include <iostream>

bool IsBitSet(int num, int pos)
{
    return (num & (1 << pos));
}

int BitwiseReverse(int num)
{
    int sizeInBits = sizeof(num) * 8; // bits
    int reversed = 0;

    for (int i = 0; i < sizeInBits; i++)
    {
        int t = num & (1 << i);
        if (t)
        {
            reversed |= (1 << (sizeInBits - i - 1));
        }
    }

    return reversed;
}

int main()
{
    int num = 5;
    std::cout << IsBitSet(num, 2) << "\n";
    std::cout << std::hex << BitwiseReverse(num);
}