//
//  main.cpp
//  CodingProblems
//
//  Created by Anand Paithankar on 4/1/19.
//  Copyright © 2019 Anand Paithankar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <array>
#include <stack>
#include <queue>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &arr)
{
	for (auto n : arr)
	{
		os << n << " ";
	}
	return os;
}

struct Entry
{
	char c;
	int v;
	Entry(char cc, int vv) : c(cc), v(vv) {}
};

void printPermutations(std::vector<Entry> &table, int mapIndex, std::string current, int usageCount)
{
	if (mapIndex == table.size())
	{
		std::cout << current << "\n";
		return;
	}

	auto c = table[mapIndex];
	for (int i = 0; i < c.v; i++)
	{
		current.push_back(c.c);
		printPermutations(table, mapIndex + 1, current, 0);
	}
}

void printPermutations(std::string &str)
{
	std::vector<Entry> table{{'a', 4}, {'b', 2}, {'c', 3}};
	printPermutations(table, 0, "", 0);
}

int main(int argc, const char *argv[])
{
	std::string str = "a2b2c3";

	printPermutations(str);
	return 0;
}
