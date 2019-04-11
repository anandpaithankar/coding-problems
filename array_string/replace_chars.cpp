#include "algo.h"

void replaceChars(std::string &str)
{
	int src = 0, dest = 0;
	while (src < str.size() && dest < str.size())
	{
		if (str[src] == 'b')
		{
			src++;
		}
		else if (src + 1 < str.size() && str[src] == 'a' && str[src + 1] == 'c')
		{
			src += 2;
		}
		else
		{
			std::swap(str[dest++], str[src++]);
		}
	}
	str.resize(dest);
}
int main()
{
	std::string str = "babaac";
	replaceChars(str);
	std::cout << str;
}