#include "algo.h"

int parseInt(const std::string &s)
{
	if (s.empty())
	{
		return INT_MAX;
	}

	int sign = s[0] == '-' ? -1 : 1;
	int start = 0;
	if (sign)
		start = 1;
	int total = 0;
	for (int i = start; i < s.length(); ++i)
	{
		total = total * 10 + (s[i] - '0');
	}
	return total * sign;
}

int main()
{
	std::cout << parseInt("-123");
}
