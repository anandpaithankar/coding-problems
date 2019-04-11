#include "algo.h"

void partition(std::vector<int> &arr)
{
	int i = 0, j = arr.size() - 1;

	while (i < j)
	{
		if (arr[i] == 0)
		{
			i++;
		}
		else if (arr[j] == 1)
		{
			j--;
		}
		else
		{
			std::swap(arr[i], arr[j]);
			i++, j--;
		}
	}
}

int main()
{
	std::vector<int> arr{0, 1, 0, 1, 0, 1, 0, 1, 0};
	partition(arr);
	std::cout << arr;
}