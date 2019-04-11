#include "algo.h"

std::string reverse_words(std::string str)
{
	int start = str.length()-1, current = str.length()-1;
	std::string temp;
	std::string result;

	while (current >= 0)
	{
		 if (str[current] == ' ') {
            std::reverse(temp.begin(), temp.end());
            temp.push_back(str[current]);
            result.append(temp);
            temp = "";
            current--;
            start = current;
        } else {
            temp.push_back(str[current]);
            current--;
        }
	}

	if (current < 0 && !temp.empty())
	{
		std::reverse(temp.begin(), temp.end());
		result.append(temp);
	}
	return result;
}

int main()
{
	std::string str = "Just do it!";
	auto result = reverse_words(str);
	std::cout << result;

}
