#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr{4, 5, 7, 8, 9, -1};
    auto result = std::max_element(arr.begin(), arr.end(),
                                   [](const int n1, const int n2) { return n1 < n2; });
    std::cout << "Max element " << *result;
}
