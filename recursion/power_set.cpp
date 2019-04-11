#include "algo.h"

void PrintPowerSet(const std::vector<int> &arr, std::vector<int> &selectedSoFar, int to_be_selected)
{
	std::cout << "to_be_Selected " << to_be_selected << "\n";
	if (to_be_selected == arr.size())
	{
		std::cout << "Hit a base case"
				  << "\n";
		std::cout << selectedSoFar;
		return;
	}

	// Powerset including arr[to_be_Selected]
	selectedSoFar.push_back(arr[to_be_selected]);
	PrintPowerSet(arr, selectedSoFar, to_be_selected + 1);

	// Powerset excluding the arr[to_be_Selected]
	std::cout << "Back " << selectedSoFar.back() << "\n";
	selectedSoFar.pop_back();
	PrintPowerSet(arr, selectedSoFar, to_be_selected + 1);
}

void PrintPowerSet(const std::vector<int> &arr)
{
	std::vector<int> selectedSoFar;
	PrintPowerSet(arr, selectedSoFar, 0);
}

int main()
{
	std::vector<int> arr{1, 2, 3};
	PrintPowerSet(arr);
}