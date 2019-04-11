
#include <iostream>
#include <vector>

using namespace std;

vector<int> merger_first_into_second(vector<int> arr1, vector<int> arr2)
{
    int m = arr1.size();
    int n = arr2.size();
    int target = n - 1;
    int i = m - 1, j = n - m - 1;

    while (i >= 0 && j >= 0)
    {
        arr2[target--] = arr1[i] > arr2[j] ? arr1[i--] : arr2[j--];
    }

    while (i >= 0)
    {
        arr2[target--] = arr1[i--];
    }

    while (j >= 0)
    {
        arr2[target--] = arr2[j--];
    }
    return arr2;
}

int main()
{
    // merge arr2 into arr1
    std::vector<int> arr1{1, 3, 5}, arr2{2, 4, 6, 0, 0, 0};
    auto r = merger_first_into_second(arr1, arr2);
    for (auto i : r)
    {
        std::cout << i << " ";
    }
}