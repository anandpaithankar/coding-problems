#include <iostream>
#include <string>
using namespace std;

bool isWildChar(char c)
{
    return (c == '*' || c == '?');
}

bool isMatch(string s, string p)
{
    int sIndex = s.length() - 1, pIndex = p.length() - 1;
    while (sIndex >= 0 && pIndex >= 0)
    {
        const auto &patternChar = p[pIndex];
        if (!isWildChar(patternChar))
        {
            if (patternChar != s[sIndex])
            {
                return false;
            }
            pIndex--;
            sIndex--;
        }
        else
        {
            if (patternChar == '*')
            {
                int i = --pIndex;
                int j = sIndex;
                while (j >= 0 && i >= 0)
                {
                    if (isWildChar(p[i]))
                    {
                        i--;
                    }
                    else if (p[i] == s[j])
                    {
                        break;
                    }
                    else
                    {
                        j--;
                    }
                }

                if (i < 0)
                {
                    return true;
                }

                if (j < 0)
                {
                    return false;
                }
                sIndex = j;
                pIndex = --i;
            }
            else
            {
                sIndex--;
                pIndex--;
            }
        }
    }
    return (sIndex == pIndex) ? true : false;
}

// "mississippi"
// "m??*ss*?i*pi"
//

bool isMatch2(string s, string p)
{
    size_t i = 0, j = 0;
    while (i < s.length() && j < p.length())
    {
        if (p[j] == '?')
        {
            i++, j++;
        }
        else if (p[j] == '*')
        {
            while (j < p.length() && p[j] == '*')
                j++;

            while (i < s.length() && j < p.length())
            {
                if (s[i++] == p[j])
                {
                    j++;
                    break;
                }
            }
        }
        else
        {
            if (p[j] != s[i])
            {
                return false;
            }
            i++, j++;
        }
    }

    if (i == s.length() && j < p.length())
    {
        // longer pattern, check if the pattern contains
        // many * and only one ?
        int count = 0;
        while (j < p.length())
        {
            if (p[j] == '*')
            {
                count++;
            }
            else if (p[j] == '?')
            {
                if (count == 0)
                    count++;
                return false;
            }
            else
            {
                return false;
            }
            j++;
        }
    }

    if (j == p.length() && i < s.length())
    {
        // longer string
        if (p[j - 1] == '*')
        {
            return true;
        }
        return false;
    }

    return (i == s.length() && j == p.length()) ? true : false;
}
int main()
{
    // std::string str = "mississippi";
    // std::string pattern = "m??*ss*?i*pi";
    std::string str = "a";
    std::string pattern = "aa";

    auto result = isMatch2(str, pattern);
    std::cout << "1. Result " << result;
    
     str = "mississippi";
     pattern = "m??*ss*?i*pi";
    result = isMatch2(str, pattern);
    std::cout << "2. Result " << result;
    
}
