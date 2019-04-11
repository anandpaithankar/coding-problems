#include <iostream>
#include <vector>

double FindMedianSortedArray(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
    if (arr1.size() > arr2.size())
    {
        return FindMedianSortedArray(arr2, arr1);
    }

    int x = arr1.size();
    int y = arr2.size();

    int low = 0, high = x;
    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? std::numeric_limits<int>::min() : arr1[partitionX - 1];
        int minRightX = (partitionX == x) ? std::numeric_limits<int>::max() : arr1[partitionX];

        int maxLeftY = (partitionY == 0) ? std::numeric_limits<int>::min() : arr2[partitionY - 1];
        int minRightY = (partitionY == y) ? std::numeric_limits<int>::max() : arr2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if ((x + y) % 2 == 0) // even
            {
                return (std::max(maxLeftX, maxLeftY) +
                        std::min(minRightX, minRightY)) /
                       2;
            }
            else
            {
                return std::max(maxLeftX, maxLeftY);
            }
        }
        else if (maxLeftX > minRightY)
        {
            high = partitionX - 1;
        }
        else
        {
            low = partitionX + 1;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> arr1{1, 3, 5, 6, 9, 11};
    std::vector<int> arr2{0, 2, 8, 11, 15, 99};

    std::cout << FindMedianSortedArray(arr1, arr2);
}