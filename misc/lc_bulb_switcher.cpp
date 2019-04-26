#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &type)
{
    for (const auto t : type)
    {
        os << t << " ";
    }
    return os;
}

int switchedOnBulbs(int n)
{
    std::vector<int> arr(n, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            if (arr[j - 1] == 0)
            {
                arr[j - 1] = 1;
            }
            else
            {
                arr[j - 1] = 0;
            }
        }
    }

    int count = 0;
    for (auto n : arr)
    {
        if (n == 1)
            count++;
    }
    return count;
}

int main()
{
    int n = 9999999;
    std::cout << switchedOnBulbs(n);
}