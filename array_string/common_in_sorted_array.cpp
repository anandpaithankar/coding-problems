#include "algo.h"

std::vector<int> commonInSortedArray(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
	if (arr1.empty() || arr2.empty())
	{
		return {};
	}

	int i = 0, j = 0;
	std::vector<int> result;

	while (i < arr1.size() && j < arr2.size())
	{
		if (arr1[i] == arr2[j])
		{
			result.push_back(arr1[i]);
			i++, j++;
		}
		else if (arr1[i] < arr2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return result;
}

int main()
{
	std::vector<int> arr1{5, 8, 9, 10}, arr2{1, 2, 5, 8, 9, 11};
	auto result = commonInSortedArray(arr1, arr2);
	std::cout << result;
}