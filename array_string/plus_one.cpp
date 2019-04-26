#include "algo.h"

void plusOne(std::vector<int> &digits)
{
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		int digit = digits[i];
		if (digit < 9)
		{
			digits[i] += 1;
			return;
		}
		else
		{
			digits[i] = 0;
		}
	}

	digits.insert(digits.begin(), 1);
}

int main()
{
	std::vector<int> arr{9, 9, 9};
	plusOne(arr);
	std::cout << arr;
}
