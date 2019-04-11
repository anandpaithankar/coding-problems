
#include "algo.h"

std::map<std::string, std::vector<size_t>> MapWords(std::string text)
{

	std::map<std::string, std::vector<size_t>> table;
	std::string::size_type startIndex = 0;
	std::string::size_type currentIndex = 0;

	currentIndex = text.find(" ", startIndex);
	while (currentIndex != std::string::npos)
	{
		auto current = text.substr(startIndex, currentIndex - startIndex);
		table[current].push_back(startIndex);
		startIndex = currentIndex + 1;
		currentIndex = text.find(" ", startIndex);
	}
	auto s = text.substr(startIndex);
	table[s].push_back(startIndex);

	return table;
}

int main(int argc, const char *argv[])
{

	std::string text = "you are very very smart";
	std::vector<std::string> words{"you", "are", "very", "intelligent"};
	std::vector<std::vector<size_t>> result;
	auto table = MapWords(text);
	for (auto word : words)
	{
		auto it = table.find(word);
		if (it == table.end())
		{
			result.push_back({INT_MAX});
		}
		else
		{
			result.push_back(it->second);
		}
	}

	for (auto x : result)
	{
		for (auto y : x)
			std::cout << y;
		std::cout << "\n";
	}

	return 0;
}
