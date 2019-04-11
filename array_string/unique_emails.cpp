#include <iostream>
#include <unordered_set>
#include <vector>

std::string filterEmail(const std::string &email)
{
    std::string localName;
    for (size_t i = 0; i < email.size(); ++i)
    {
        if (email[i] == '.')
        {
            continue;
        }
        else if (email[i] == '+' || email[i] == '@')
        {
            break;
        }
        localName += email[i];
    }

    std::string domain = std::strstr(email.c_str(), "@");
    return localName + domain;
}

int numUniqueEmails(std::vector<std::string> &emails)
{
    std::unordered_set<std::string> uniqueEmails;
    for (auto email : emails)
    {
        auto filteredEmail = filterEmail(email);
        std::cout << filteredEmail << "\n";
        uniqueEmails.insert(filteredEmail);
    }
    return uniqueEmails.size();
}

int main()
{
    std::vector<std::string> emails{"test.e.mail+bob.cathy@leetcode.com",
                                    "test.email+alex@leetcode.com",
                                    "testemail+david@lee.tcode.com"};
    std::cout << numUniqueEmails(emails);
}
