#include "algo.h"

int firstUniqueInt(const std::vector<int> &arr)
{
	int unique = 0;
	for (const auto &n : arr)
	{
		unique ^= n;
	}

	return unique;
}

int main()
{
	std::vector<int> arr{2,1,1,8,6,8,6};
	std::cout << firstUniqueInt(arr);

}