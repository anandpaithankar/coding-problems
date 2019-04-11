#include "algo.h"

void subsetSum(std::vector<int> &arr, int sum, int currentSum, int currentIndex, std::vector<int> solution)
{
	if (currentIndex == arr.size())
	{
		if (sum == currentSum)
		{
			std::cout << solution;
		}
		return;
	}

	for (int i = currentIndex; i < arr.size(); i++)
	{
		solution.push_back(arr[i]);
		subsetSum(arr, sum, currentSum + arr[i], currentIndex + 1, solution);
		solution.pop_back();
		subsetSum(arr, sum, currentSum, currentIndex + 1, solution);
	}
}

void subsetSum(std::vector<int> &arr, int sum)
{
	int currentSum = 0;
	std::vector<int> solution;
	subsetSum(arr, sum, 0, 0, solution);
}

int main()
{
	std::vector<int> arr{3, 2, 7, 1};
	int sum = 6;

	subsetSum(arr, sum);
}