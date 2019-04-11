#include <iostream>
#include <vector>

int MaxRepeatingNumber(std::vector<int> &arr, int k)
{
    for (size_t i = 0; i < arr.size(); i++)
        arr[arr[i] % k] += k;

    int max = arr[0];
    int maxElementIndex = 0;
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (max < arr[i] / k)
        {
            max = arr[i] / k;
            maxElementIndex = i;
        }
    }

    return max;
}

int main()
{
    std::vector<int> arr{2, 3, 3, 5, 3, 4, 1, 7};
    std::cout << MaxRepeatingNumber(arr, arr.size());
}