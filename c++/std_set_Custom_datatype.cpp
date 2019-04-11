#include <iostream>
#include <unordered_set>
#include <vector>
#include <functional>
#include <unordered_map>

using Pair = std::pair<int, int>;

struct PairHasher
{
    size_t operator()(const Pair &p) const
    {
        auto h1 = std::hash<int>()(p.first);
        auto h2 = std::hash<int>()(p.second);
        return (h1 ^ (h2 << 1)); // hash_combine
    }
};

struct PairComparator
{
    bool operator()(const Pair &p1, const Pair &p2) const
    {
        return (p1.first == p2.first) && (p1.second == p2.second);
    }
};

int main()
{
    std::unordered_set<Pair, PairHasher, PairComparator> unique;
}