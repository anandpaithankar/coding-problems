#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int start, int end, int pivotIndex)
{
    // Swap pivot with the element at end position
    std::swap(arr[end], arr[pivotIndex]);
    int pivot = arr[end];

    int i = start;
    for (int current = start; current <= end - 1; current++)
    {
        if (arr[current] <= pivot)
        {
            std::swap(arr[current], arr[i]);
            i++;
        }
    }
    std::swap(arr[end], arr[i]);
    return i;
}

int choosePivot(int start, int end)
{
    std::srand(std::time(nullptr));
    int v = start + std::rand() % (end - start);
    return v;
}

void quickSort(std::vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int p = choosePivot(start, end);
        int pivot = partition(arr, start, end, p);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int main()
{
    std::vector<int> arr{5, 2, 8, 9, 0, 11}; // Sorted {0,1,2,5,8,9,11}
    //std::cout << "partitionIndex " << partition(arr, 0, arr.size() - 1, 6) << "\n";
    quickSort(arr, 0, arr.size() - 1);

    for (auto r : arr)
    {
        std::cout << r << " ";
    }
}