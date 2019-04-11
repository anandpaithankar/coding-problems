#include <iostream>
#include <vector>

void dutchFlag(std::vector<char> &flag)
{
    int zeroIndex = 0;
    int twoIndex = flag.size() - 1;
    int current = 0;

    while (current <= twoIndex)
    {
        if (flag[current] == 'R')
        {
            std::swap(flag[current++], flag[zeroIndex++]);
        }
        else if (flag[current] == 'B')
        {
            std::swap(flag[current], flag[twoIndex--]);
        }
        else
            current++;
    }
}

int main()
{
    std::vector<char> arr{'G', 'R', 'B'};
    dutchFlag(arr);
    for (auto r : arr)
    {
        std::cout << r << " ";
    }
}