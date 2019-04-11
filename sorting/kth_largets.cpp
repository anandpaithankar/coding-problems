#include "algo.h"

// Find kth largest element in an array
int choosePivot(std::vector<int> &arr, int start, int end)
{
	int pivot = arr[end];
	int j = start;
	for (int i = start; i <= end - 1; i++)
	{
		// partition this array such that elements greater than pivot
		// will be on the left handside and elements less than pivot
		// will fall on the right handside.
		//
		// for kth minimum - use arr[i] < pivot
		if (arr[i] > pivot)
		{
			std::swap(arr[i], arr[j]);
			j++;
		}
	}
	std::swap(arr[end], arr[j]);
	return j;
}

int quickSelect(std::vector<int> &arr, int start, int end, int k)
{
	if (start <= end)
	{
		int pivot = choosePivot(arr, start, end);
		if (pivot == k - 1)
		{
			return arr[pivot];
		}
		else if (pivot > k - 1)
		{
			return quickSelect(arr, start, pivot - 1, k);
		}
		else
		{
			return quickSelect(arr, pivot + 1, end, k);
		}
	}
	return -1;
}

int kthLargest(std::vector<int> &arr, int k)
{
	return quickSelect(arr, 0, arr.size() - 1, k);
}

int main()
{
	std::vector<int> arr{4, 1, 8, 11, 2, 5, 6};
	int k = 4;

	std::cout << kthLargest(arr, k);
}