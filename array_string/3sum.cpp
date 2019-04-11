#include <iostream>
#include <vector>

// find 3 numbers summing to zero.
std::vector<std::vector<int>> threeSum(const std::vector<int> &nums, int sum = 0)
{
    if (nums.empty())
    {
        return {};
    }
    std::vector<std::vector<int>> result;
    std::vector<int> arr(nums);
    std::sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    for (size_t i = 0; i < arr.size() - 2; i++)
    {
        left = i + 1;
        right = arr.size() - 1;
        while (left < right)
        {
            int s = arr[i] + arr[left] + arr[right];
            if (s == 0)
            {
                std::vector<int> r{arr[i], arr[left], arr[right]};
                if (result.empty() || result.back() != r)
                    result.push_back(r);
                left++, right--;
            }
            else if (s < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    std::vector<int> arr{};
    auto result = threeSum(arr, 0);
    for (auto r : result)
    {
        for (auto n : r)
            std::cout << n << " ";
        std::cout << "\n";
    }
}