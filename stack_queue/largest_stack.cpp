#include <iostream>
#include <stack>

class MaxStack
{
private:
    std::stack<int> _main;
    std::stack<int> _max;

public:
    void push(int x)
    {
        _main.push(x);
        if (_max.empty())
        {
            _max.push(x);
        }
        else
        {
            if (x > _max.top())
            {
                _max.push(x);
            }
        }
    }

    int top()
    {
        if (_main.empty())
        {
            return -1;
        }
        return _main.top();
    }

    void pop()
    {
        if (!_main.empty())
        {
            auto x = _main.top();
            if (!_max.empty())
            {
                if (x == _max.top())
                {
                    _max.pop();
                }
            }
        }
    }

    int getMax()
    {
        if (_max.empty())
        {
            return -1;
        }
        return _max.top();
    }
};
int main()
{
    MaxStack max;

    max.push(6);
    max.push(5);
    std::cout << "Max " << max.getMax() << "\n";

    max.push(4);
    max.push(11);
    //max.pop();
    std::cout << "Max " << max.getMax() << "\n";

    max.pop();
    std::cout << "Max " << max.getMax() << "\n";
}