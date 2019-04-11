#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>
#include <stack>

using namespace std;

std::array<std::string, 8> combinations{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations(string digits, std::string current, int index, std::vector<string> &result)
{
	if (index == digits.size())
	{
		result.push_back(current);
		return;
	}

	int digit = digits[index] - '0';
	for (auto c : combinations[digit - 2])
	{
		current.push_back(c);
		letterCombinations(digits, current, index + 1, result);
		current.pop_back();
	}
}

vector<string> letterCombinations(string digits)
{
	std::vector<string> result;
	letterCombinations(digits, "", 0, result);
	return result;
}

int main()
{
	std::string str = "2347";
	auto result = letterCombinations(str);
	for (auto &r : result)
	{
		std::cout << r << " ";
	}
}