#include <iostream>
#include <vector>

void RotateLeft(std::vector<int> &arr, int k)
{
    std::reverse(arr.begin(), arr.begin() + k - 1);
    std::reverse(arr.begin() + k, arr.end());
    std::reverse(arr.begin(), arr.end());
}

int main()
{
    std::vector<int> arr{4, 5, 6, 7, 8, 9};
    RotateLeft(arr, 3);
    for (auto n : arr)
    {
        std::cout << n << " ";
    }
}