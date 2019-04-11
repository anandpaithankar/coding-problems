#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <array>
#include <string>

using namespace std;

using IntGrid = std::vector<std::vector<int>>;
using CharGrid = std::vector<std::vector<char>>;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &arr)
{
	for (auto n : arr)
	{
		os << n << " ";
	}
	std::cout << "\n";
	return os;
}

