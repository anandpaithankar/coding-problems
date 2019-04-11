#include <iostream>
#include <cstring>

void Copy(const char *pszSource, size_t uMaxLen, char *pszCopy)
{
    std::memcpy(pszCopy, pszSource, uMaxLen + 1);
}

int main()
{
    std::string str = "this is me!";
    char *pszDest = new char[(str.length() + 1)];
    Copy(str.c_str(), str.length(), pszDest);
    std::cout << pszDest;
}