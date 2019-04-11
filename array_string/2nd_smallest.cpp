#include <iostream>
#include <vector>

int getSecondMax(const std::vector<int> &arr)
{
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;

    for (auto n : arr)
    {
        secondMax = std::max(std::min(firstMax, n), secondMax);
        firstMax = std::max(firstMax, n);
    }

    return secondMax;
}

int main()
{
    std::vector<int> arr{5, 2, 9, 1, 4, 11, 24};
    std::cout << "Second max element " << getSecondMax(arr);
}