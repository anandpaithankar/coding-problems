#include <iostream>
#include <vector>

bool hasSubarraySum(const std::vector<int> &arr, int sum)
{
    if (arr.empty())
    {
        return sum == 0;
    }

    int curr_sum, i, j;

    // Pick a starting point
    for (i = 0; i < arr.size(); i++)
    {
        curr_sum = arr[i];

        // try all subarrays starting with 'i'
        for (j = i + 1; j <= arr.size(); j++)
        {
            if (curr_sum == sum)
            {
                return true;
            }
            if (curr_sum > sum || j == arr.size())
                break;
            curr_sum = curr_sum + arr[j];
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> arrs{{10, -3, 1, 1},
                                       {10, 5, 2, 1},
                                       {10, 5, 3, 3},
                                       {10, 5, 3, -2}};

    for (auto v : arrs)
    {
        std::cout << hasSubarraySum(v, 8) << "\n";
    }
}