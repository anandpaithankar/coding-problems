#include <stdio.h>

double Median(int arr[], int size)
{
    if (size & 1)
    {
        return arr[size / 2];
    }
    else
    {
        // even
        return (arr[size / 2] + arr[(size / 2) - 1]) / 2;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%f", Median(arr, size));
}