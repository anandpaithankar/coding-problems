#include "algo.h"

int maxLengthWithoutRepeatingChars(const std::string &str)
{
	int charMap[256] = {-1};
	int i = 0, maxLength = 0;
	for (int j = 0; j < str.length(); ++j) {
		if (charMap[str[j]] >= i) {
			i = charMap[str[j]] + 1;
		}

		charMap[str[j]] = j;
		std::cout << "i " << i << "\n";
		maxLength = std::max(j-i+1, maxLength);
		std::cout << "maxLength " << maxLength << "\n";
	}
	return maxLength;
}

int main()
{
	std::string str("abcdcedf");
	std::cout << maxLengthWithoutRepeatingChars(str);

}