
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <array>
#include <stack>
#include <queue>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &arr)
{
	for (auto n : arr)
	{
		os << n << " ";
	}
	return os;
}

int minDistanceBetweenWords(const std::vector<std::string> &text, const std::string& w1, const std::string& w2)
{

	int start = 0;
	int minDistance = INT_MAX;
	std::string lookingFor = w1;
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == w1)
		{
			lookingFor = w2;
			start = i;
		}

		if (lookingFor == w2)
		{
			minDistance = std::min(minDistance, i - start);
			lookingFor = w1;
		}
	}
	return minDistance;
}
std::vector<std::string> split(std::string &text, std::string delimiter)
{
	std::vector<std::string> result;
	int start = 0;
	auto index = text.find_first_of(" ");
	while (index != std::string::npos)
	{
		result.push_back(text.substr(start, index));
		text = text.substr(index + 1);
		index = text.find_first_of(" ");
	}
	result.push_back(text);
	return result;
}

int main(int argc, const char *argv[])
{
	std::string str = "The quick brown fox jumps over the lazy dog and jumps over another fox.";
	auto v = split(str, " ");
	std::cout << minDistanceBetweenWords(v, "fox", "over");
	return 0;
}
