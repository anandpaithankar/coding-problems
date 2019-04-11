#include <iostream>
#include <string>

void reverseStr(std::string &str, int i, int j)
{
    while (i < j)
    {
        std::swap(str[i], str[j]);
        i++, j--;
    }
}

void reverseWords(std::string &A)
{
    std::reverse(A.begin(), A.end());

    int j = 0;
    for (auto i = 0; i < A.size(); i++)
    {
        if (A[i] == ' ')
        {
            reverseStr(A, j, i - 1);
            j = i + 1;
        }
    }

    reverseStr(A, j, A.length() - 1);
}

void reverse2(std::string &str)
{
    size_t size = str.size();
    for (size_t i = 0; i < size / 2; ++i)
    {
        std::swap(str[i], str[size - i - 1]);
    }
}

int main()
{
    std::string str = "the sky is blue";
    reverseWords(str);
    std::cout << "\n"
              << str;
    reverse2(str);
    std::cout << "\n"
              << str;
}