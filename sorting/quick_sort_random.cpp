#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // swap pivot into median place
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randompivot(std::vector<int> &arr, int low, int high)
{
    std::srand(time(nullptr));
    int random = low + std::rand() % (high - low);
    std::swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int index = randompivot(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

int main()
{
    std::vector<int> arr{4, 1, 2, 7, 11, 0};

    int low = 0, high = arr.size() - 1;
    quickSort(arr, low, high);
    for (auto r : arr)
    {
        std::cout << r << " ";
    }
}
