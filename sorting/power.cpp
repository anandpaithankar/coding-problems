#include <iostream>

int power(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }

    return base * power(base, exp - 1);
}

int main()
{
    int base = 9;
    int exp = 2;

    std::cout << power(base, exp);
}