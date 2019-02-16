#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

typedef struct TrieNode
{
    std::string word; // word in the node.
    std::unordered_map<char, TrieNode *> children;
    TrieNode(const std::string &w = "") : word(w) {}
} TrieNode;

TrieNode *Insert(TrieNode *root, const std::string &word)
{
    if (root == nullptr)
    {
        root = new TrieNode;
    }

    TrieNode *current = root;
    for (char c : word)
    {
        if (current->children.count(c))
        {
            current = current->children[c];
        }
        else
        {
            current->children[c] = new TrieNode;
            current = current->children[c];
        }
    }

    // todo: where to put the word in a node
    if (!word.empty())
    {
        current->word = word;
    }
    return root;
}

bool Contains(TrieNode *root, const std::string &word)
{
    TrieNode *current = root;
    for (const char &c : word)
    {
        if (current->children.count(c))
        {
            current = current->children[c];
        }
    }
    if (!word.empty() && current->word == word)
    {
        return true;
    }
    return false;
}

std::vector<std::string> AutoCompleteSuggestions(TrieNode *root, const std::string &partial)
{
    std::vector<std::string> suggestions;
    TrieNode *current = root;
    for (const char &c : partial)
    {
        if (current->children.count(c))
        {
            if (current->word == partial)
            {
                suggestions.push_back(current->word);
                return suggestions;
            }

            current = current->children[c];
        }
    }

    // the partial is finished.. now perform BFS (level order traversal)
    std::queue<TrieNode *> q;
    q.push(current);
    while (!q.empty())
    {
        TrieNode *t = q.front();
        q.pop();

        if (!t->word.empty())
        {
            suggestions.push_back(t->word);
        }

        for (const auto &it : t->children)
        {
            q.push(it.second);
        }
    }

    return suggestions;
}

TrieNode *DeleteWord(TrieNode *root, const std::string &word)
{
    TrieNode **prev = nullptr;
    TrieNode *current = root;
    for (const char &c : word)
    {
        if (current->children.count(c))
        {
            prev = &current;
            current = current->children[c];
        }
    }

    if (!word.empty() && current != nullptr)
    {
        current->word = "";
        if (current->children.size() == 0)
        {
            *prev = nullptr;
            delete current;
        }
    }
    return root;
}

int main()
{
    std::vector<std::string> dict{"peter", "piper", "picked", "peck", "pickled", "peppers"};
    TrieNode *root = new TrieNode;

    for (const auto &word : dict)
    {
        root = Insert(root, word);
    }

    std::string word = "pickled";
    std::cout << "Looking for word " << word << " " << Contains(root, word) << "\n";

    std::cout << "Auto complete suggestions \n";
    auto suggestions = AutoCompleteSuggestions(root, "pic");
    for (const auto w : suggestions)
    {
        std::cout << w << " ";
    }

    root = DeleteWord(root, word);
    std::cout << "\nAfter deleting word, lookup " << word << " " << Contains(root, word) << "\n";
}