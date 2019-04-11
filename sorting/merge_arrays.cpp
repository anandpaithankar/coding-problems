#include "algo.h"

// Merge two sorted arrays.
// Merge one array into another one without creating another buffer.
//
// A = {1,3,5,0,0,0}
// B = {2,4,6}
//  ==> {1,2,3,4,5,6}
void MergeArrays(std::vector<int> &arr1, std::vector<int> &arr2)
{

    int aIndex = arr1.size() - 1;
    int bIndex = arr2.size() - 1;
    int mergeIndex = arr1.size() + arr2.size() - 1;

    arr1.resize(arr1.size() + arr2.size(), 0);

    while (aIndex >= 0 && bIndex >= 0)
    {
        if (arr1[aIndex] > arr2[bIndex])
        {
            arr1[mergeIndex] = arr1[aIndex];
            aIndex--;
        }
        else
        {
            arr1[mergeIndex] = arr2[bIndex];
            bIndex--;
        }
        mergeIndex--;
    }
}

int main()
{
    std::vector<int> arr1{1, 3, 9};
    std::vector<int> arr2{2, 4, 6};

    MergeArrays(arr1, arr2);
    for (auto n : arr1)
    {
        std::cout << n << " ";
    }
}