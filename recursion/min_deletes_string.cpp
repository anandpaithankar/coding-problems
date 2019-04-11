#include <iostream>
#include <unordered_set>
#include <queue>

int stringDelete(std::string &query, std::unordered_set<std::string> &dict)
{
    std::queue<std::string> q;
    std::unordered_set<std::string> qElements;

    q.push(query);
    qElements.insert(query);

    while (!q.empty())
    {
        std::string s = q.front();
        q.pop();
        qElements.erase(s);
        if (dict.count(s))
        {
            return query.length() - s.length();
        }

        for (int i = 0; i < s.length(); i++)
        {
            std::string sub = s.substr(0, i) + s.substr(i + 1, s.length());
            if (sub.length() > 0 && qElements.count(sub) == 0)
            {
                q.push(sub);
                qElements.insert(sub);
            }
        }
    }
    return -1;
}

int minDistance(std::string &word1, std::string &word2)
{
    std::queue<std::string> q;
    std::unordered_set<std::string> qElements;

    q.push(word1);
    qElements.insert(word1);

    while (!q.empty())
    {
        std::string s = q.front();
        q.pop();
        qElements.erase(s);

        if (s == word2)
        {
            return word1.length() - s.length();
        }

        for (int i = 0; i < s.length(); i++)
        {
            std::string sub = s.substr(0, i) + s.substr(i + 1, s.length());
            if (sub.length() > 0 && qElements.count(sub) == 0)
            {
                std::cout << sub << "\n";
                q.push(sub);
                qElements.insert(sub);
            }
        }
    }
    return -1;
}

int main()
{
    std::unordered_set<std::string> dict{"a", "aa", "aaa"};
    std::string query = "abc";
    std::cout << stringDelete(query, dict) << "\n";

    std::string word1 = "horse", word2 = "ros";
    int result = minDistance(word1, word2);
    std::cout << result;
}
