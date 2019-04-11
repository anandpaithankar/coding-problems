#include "algo.h"

/**
 * Return the max product of any three integers in array.
 * 
 * Input: [-10, -10, 5, 2] Output: 500 (-10 x -10 x 5)
 */

// Time: O(n log n) + O(n) Space: O(1)
int maxProduct(std::vector<int> &arr)
{
	if (arr.empty())
		return INT_MIN;
	
	std::sort(arr.begin(), arr.end());

	// Look at the following method to compute the necessary values without
	// going over the entire array.
	//
	// std::max(arr[0] * arr[1] * arr[n - 1], arr[n - 1] * arr[n - 2] * arr[n - 3]);
	// The time complexity would be O(n log n) only.
	int maxProduct = INT_MIN;
	int product= 0;
	int left = 0, right = arr.size()-1;
	for (int i = 0; i < arr.size()-2; i++)
	{
		left = i+1;
		right = arr.size()-1;
		while(left < right)
		{
			product = arr[i] * arr[left] * arr[right];
			if (product > maxProduct)
			{
				maxProduct = product;
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	return maxProduct;
}

// Time: O(n) and Space: O(1)
// Compute First , second and third max values from array followed by first and second min.
int maxProduct_Better(std::vector<int> arr)
{
	if (arr.size() < 3)
	{
		return INT_MIN;
	}

	int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
	int firstMin = INT_MAX, secondMin = INT_MAX;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > firstMax)
		{
			thirdMax = secondMax;
			secondMax = firstMax;
			firstMax = arr[i];
		}
		else if (arr[i] > secondMax)
		{
			thirdMax = secondMax;
			secondMax = arr[i];
		}
		else if (arr[i] > thirdMax)
		{
			thirdMax = arr[i];
		}

		if (arr[i] < firstMin)
		{
			secondMin = firstMin;
			firstMin = arr[i];
		}
		else if (arr[i] < secondMin)
		{
			secondMin = arr[i];
		}
	}

	return std::max(firstMin * secondMin * firstMax, firstMax * secondMax * thirdMax);
}

int main()
{
	std::vector<int> arr {-10, -10, 95, 13, 8, -20};
	std::cout << maxProduct_Better(arr);
}