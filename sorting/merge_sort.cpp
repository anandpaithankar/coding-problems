#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;

    std::vector<int> sorted(end - start + 1);
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            sorted[k++] = arr[i++];
        }
        else
        {
            sorted[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        sorted[k++] = arr[i++];
    }

    while (j <= end)
    {
        sorted[k++] = arr[j++];
    }

    for (int i = start, k = 0; i <= end; i++, k++)
    {
        arr[i] = sorted[k];
    }
}

void mergeSort(std::vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    std::vector<int> arr{5, 8, 1, 2};
    int start = 0, end = arr.size() - 1;

    mergeSort(arr, start, end);

    for (auto &r : arr)
    {
        std::cout << r << " ";
    }
}