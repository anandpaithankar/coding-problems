#include "algo.h"

using namespace std;

struct FrequencyAndWord
{
    int count;
    std::string word;
};

vector<string> solve(vector<string> arr)
{
    std::unordered_map<std::string, FrequencyAndWord> m;
    for (auto s : arr)
    {
        auto it = s.find(" ");
        std::string key = s.substr(0, it);
        std::string value = s.substr(it + 1);
        auto iter = m.find(key);
        if (iter != m.end())
        {
            iter->second.count++;
            iter->second.word = strcmp(iter->second.word.c_str(), value.c_str()) >= 0 ? iter->second.word : value;
        }
        else
        {
            m[key] = {1, value};
        }
    }
    std::vector<string> result;
    for (auto e : m)
    {
        result.push_back(e.first + ":" + std::to_string(e.second.count) + "," + e.second.word);
    }
    return result;
}

int main()
{
    std::vector<std::string> input{
        "key1 abcd",
        "key2 zzz",
        "key1 hello",
        "key3 world",
        "key1 hello"};
    auto result = solve(input);
    for (auto r : result)
    {
        std::cout << r << "\n";
    }
}
