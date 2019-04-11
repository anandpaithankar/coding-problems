#include <iostream>

int mystrstr(const std::string &haystack, const std::string &needle)
{
    int n = haystack.size();
    int count = 0;
    int m = needle.size();

    for (int i = 0; i < n; i++)
    {
        count = 0;
        if (haystack[i] == needle[0])
        {
            for (int k = 0; k < m; k++)
            {
                if (haystack[i + k] == needle[k])
                {
                    count++;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        if (count == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::string text = "babbaaabaaaabbababaaabaabbbbabaaaabbabbabaaaababbabbbaaabbbaaabbbaabaabaaaaababbaaaaaabababbbbba";
    std::string pattern = "bababbbbbbabbbaabbaaabbbaababa";
    std::cout << mystrstr(text, pattern);
}