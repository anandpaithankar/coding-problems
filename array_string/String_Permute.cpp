#include "algo.h"

void Permute(std::vector<char> &arr, int i)
{
    if (i >= arr.size() - 1)
    {
        std::cout << "\n";
        for (auto n : arr)
        {
            std::cout << n << " ";
        }
        return;
    }

    for (int j = i; j < arr.size(); j++)
    {
        std::swap(arr[i], arr[j]);
        Permute(arr, i + 1);
        std::swap(arr[i], arr[j]);
    }
}

void PrintPermutation(std::vector<char> &arr)
{
    Permute(arr, 0);
}

int main()
{
    std::vector<char> arr{'a', 'b', 'c', 'd'};
    PrintPermutation(arr);
}
