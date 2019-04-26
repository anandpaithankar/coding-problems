#include <iostream>
#include <vector>

bool isEven(int num)
{
	return (num%2 == 0) ? true : false;
}

void removeEven(std::vector<int> &arr)
{
	int i = 0, j = 0;
	while (j < arr.size())
	{
		if (!isEven(arr[j]))
		{
			std::swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	
	arr.resize(i);
}

void removeEvens2(std::vector<int> &arr)
{
	int j = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if(arr[i] % 2 == 1)
		{
			arr[j] = arr[i];
			j++;
		}
	}
	arr.resize(j);
}

int main()
{
	std::vector<int> arr{1,2,4,5,10,6,3};
	//arr = {2,1,5,8,6,11};
	removeEven(arr);
	for (const auto &n : arr)
	{
		std::cout << n << " ";
	}
}