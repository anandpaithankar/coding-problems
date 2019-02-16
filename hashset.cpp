#include <iostream>
#include <cassert>

// Hash table to store only strings. (Not a key-value pair).
// This data structure acts as a HashSet or Set, instead of a traditional hashtable.
typedef struct Node
{
    char *str;
    struct Node *next;

    Node() : str(nullptr), next(nullptr) {}
    ~Node()
    {
        if (str)
            free(str);
    }
} Node;

typedef struct HashSet
{
    int size;
    Node **table; // array of array
} HashSet;

HashSet *CreateHashSet(int size)
{
    HashSet *newTable;

    if (size < 1)
        return nullptr;

    newTable = new HashSet;
    assert(newTable != nullptr);

    newTable->table = static_cast<Node **>(malloc(sizeof(Node *) * size));
    assert(newTable->table);

    // initialize
    for (int i = 0; i < size; i++)
    {
        newTable->table[i] = nullptr;
    }

    newTable->size = size;

    return newTable;
}

unsigned int Hash(HashSet *hashSet, const char *str)
{
    unsigned int hashVal = 0;

    for (; *str != 0; str++)
    {
        hashVal = *str + (hashVal << 5) - hashVal;
    }
    return hashVal % hashSet->size;
}

Node *Lookup(HashSet *hashSet, const char *str)
{
    Node *list;
    unsigned int hashVal = Hash(hashSet, str);

    for (list = hashSet->table[hashVal]; list != nullptr; list = list->next)
    {
        if (list->str && strcmp(str, list->str) == 0)
            return list;
    }
    return nullptr;
}

int AddString(HashSet *hashSet, const char *str)
{
    Node *currentList;
    unsigned int hashVal = Hash(hashSet, str);

    if (hashSet->table[hashVal] == nullptr)
    {
        hashSet->table[hashVal] = new Node;
    }

    // Does item already exist?
    currentList = Lookup(hashSet, str);

    // Item exists, dont insert again.
    if (currentList != nullptr)
        return 0;

    // Insert into list;
    Node *newList = new Node;
    newList->str = strdup(str);
    newList->next = hashSet->table[hashVal];
    hashSet->table[hashVal] = newList;

    return 1;
}

void FreeTable(HashSet *hashSet)
{
    int i;
    Node *list, *temp;

    if (hashSet == nullptr)
        return;

    for (i = 0; i < hashSet->size; i++)
    {
        list = hashSet->table[i];
        while (list != nullptr)
        {
            temp = list;
            list = list->next;
            delete temp;
        }
    }

    free(hashSet->table);
    free(hashSet);
}

int main()
{
    HashSet *hashSet = CreateHashSet(5);
    assert(hashSet != nullptr);

    const std::string str = "Jupiter";
    AddString(hashSet, str.c_str());
    AddString(hashSet, "Venus");
    AddString(hashSet, "Mercury");

    Node *n = Lookup(hashSet, "Earth");
    if (n)
    {
        std::cout << "Name found is " << n->str;
    }
    else
    {
        std::cout << "Name not found \n";
    }

    FreeTable(hashSet);

    return 0;
}
