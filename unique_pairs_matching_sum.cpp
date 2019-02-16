#include <iostream>
#include <unordered_set>
#include <vector>
#include <functional>

using Pair = std::pair<int,int>;
struct PairHasher
{
    size_t operator()(const Pair &p1) const noexcept {
        size_t h1 = std::hash<int>{}(p1.first);
        size_t h2 = std::hash<int>{}(p1.second);
        return h1 ^ (h2 << 1);
    }
};

struct PairComparator
{
    bool operator()(const Pair &p1, const Pair &p2) const
    {
        return ((p1.first == p2.first) && (p1.second == p2.second)) ||
        ((p1.first == p2.second) && (p1.second == p2.first));
    }
};


using UniquePairs = std::unordered_set<Pair,PairHasher,PairComparator>;

UniquePairs getAllMatchingPairs(const std::vector<int> &arr, int k)
{
    UniquePairs uniquePairs;

    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = i + 1; j < arr.size(); j++)
        {
            if (k - arr[i] == arr[j])
            {
                uniquePairs.insert(std::make_pair(arr[i], arr[j]));
            }
        }
    }
    return uniquePairs;
}

int main()
{
    std::vector<int> arr{1, 3, 2, 5, 46, 6, 7, 4};
    int k = 5;

    auto result = getAllMatchingPairs(arr, k);
    for (auto r : result)
    {
        std::cout << r.first << "," << r.second << "\n";
    }
}