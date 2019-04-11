#include <iostream>
#include <vector>

std::string WordWrap(std::vector<std::string> &words, size_t maxWidth, size_t index)
{
    if (index > words.size())
    {
        return {};
    }

    std::string result;
    size_t currentLength = 0;
    size_t remainingLength = maxWidth;
    while (result.length() < maxWidth && index < words.size())
    {
        // Check if the word (including a space) can fit in the remaining space.
        if (remainingLength >= words[index].size() + 1) // 1 for space
        {
            if (!result.empty())
            {
                result += " " + words[index];
                currentLength = words[index].size() + 1;
            }
            else
            {
                result += words[index];
                currentLength = words[index].size();
            }
            remainingLength -= currentLength;
            index++;
        }
        else if (remainingLength > 0)
        {
            // Fill up the remaining length by whitespaces
            for (size_t i = 0; i < remainingLength; i++)
            {
                result += " ";
            }
            remainingLength = 0;
        }
        return result + "\n" + WordWrap(words, maxWidth, index);
    }
    return "";
}

std::string WordWrap(std::vector<std::string> &words, size_t maxWidth)
{
    size_t index = 0;
    return WordWrap(words, maxWidth, index);
}

int main()
{
    std::vector<std::string> words{"This", "is", "a", "text", "justification", "problem"};
    size_t maxWidth = 30;
    std::cout << WordWrap(words, maxWidth);
}