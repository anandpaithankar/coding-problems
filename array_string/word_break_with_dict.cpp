#include "algo.h"

bool isWord(const std::string &s, const std::vector<std::string> &wordDict)
{
	for (auto &w : wordDict)
	{
		if (s == w)
		{
			return true;
		}
	}
	return false;
}

bool wordBreak(string s, std::string &current, const std::vector<string> &wordDict)
{
	if (s.empty())
	{
		return true;
	}
	int index = 0;
	string word;
	while (index < s.size())
	{
		word.push_back(s[index]);
		if (isWord(word, wordDict))
		{
			current += word + " ";
			if (wordBreak(s.substr(index + 1), current, wordDict))
			{
				return true;
			}
			index++;
		}
		else
		{
			index++;
		}
	}

	return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
	std::string str;
	auto result = wordBreak(s, str, wordDict);
	std::cout << str << "\n"
			  << result;
	return result;
}

int main()
{
	std::vector<std::string> wordDict{"cats", "dog", "sand", "and", "cat"};
	std::string s = "catsandog";
	wordBreak(s, wordDict);
}