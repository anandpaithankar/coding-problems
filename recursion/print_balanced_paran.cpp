#include <iostream>

void printParan(std::string str, int left, int right)
{
    if (left == 0 && right == 0)
    {
        std::cout << str << " ";
        return;
    }

    if (left > 0)
    {
        printParan(str + "(", left - 1, right + 1);
    }

    if (right > 0)
    {
        printParan(str + ")", left, right - 1);
    }
}

int main()
{
    int n = 2;
    std::string str;
    printParan(str, n, 0);
}