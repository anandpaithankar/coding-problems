#include "algo.h"

// Merge k-sorted arrays
//
// E.g. {1,4,7} {2,5,8} {3,6,9} => {1,2,3,4,5,6,7,8,9}
struct CompareIterator
{
    std::vector<int>::const_iterator current;
    std::vector<int>::const_iterator end;

    bool operator<(const CompareIterator &that) const
    {
        return *current > *that.current;
    }
};

std::vector<int> MergeSortedArrays(const std::vector<std::vector<int>> &arrays)
{
    std::priority_queue<CompareIterator, std::vector<CompareIterator>> pq;
    for (const auto &arr : arrays)
    {
        pq.emplace(CompareIterator{arr.cbegin(), arr.cend()});
    }

    std::vector<int> result;

    while (!pq.empty())
    {
        auto smallest = pq.top();
        pq.pop();
        if (smallest.current != smallest.end)
        {
            result.emplace_back(*smallest.current);
            pq.emplace(CompareIterator{std::next(smallest.current), smallest.end});
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> arrs{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    auto result = MergeSortedArrays(arrs);
    for (auto n : result)
    {
        std::cout << n << " ";
    }
    return 0;
}
