#include <iostream>

// 0001

int BitwiseReverse(int num)
{
    int numBits = sizeof(num) * 8;
    int reversed = 0;

    for (int i = 0; i < numBits; i++)
    {
        int x = num & (1 << i); // check if bit is set
        if (x)
        {
            reversed |= (1 << (numBits - i - 1)); // set the bit
        }
    }
    return reversed;
}

int main(int argc, char const *argv[])
{
    unsigned int v = 2;
    std::cout << "\n"
              << BitwiseReverse(v); // 100
    return 0;
}
