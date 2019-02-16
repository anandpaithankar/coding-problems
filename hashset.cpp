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

unsigned int Hash(HashSet *hashTable, const char *str)
{
    unsigned int hashVal = 0;

    for (; *str != 0; str++)
    {
        hashVal = *str + (hashVal << 5) - hashVal;
    }
    return hashVal % hashTable->size;
}

Node *Lookup(HashSet *hashTable, const char *str)
{
    Node *list;
    unsigned int hashVal = Hash(hashTable, str);

    for (list = hashTable->table[hashVal]; list != nullptr; list = list->next)
    {
        if (list->str && strcmp(str, list->str) == 0)
            return list;
    }
    return nullptr;
}

int AddString(HashSet *hashTable, const char *str)
{
    Node *currentList;
    unsigned int hashVal = Hash(hashTable, str);

    if (hashTable->table[hashVal] == nullptr)
    {
        hashTable->table[hashVal] = new Node;
    }

    // Does item already exist?
    currentList = Lookup(hashTable, str);

    // Item exists, dont insert again.
    if (currentList != nullptr)
        return 0;

    // Insert into list;
    Node *newList = new Node;
    newList->str = strdup(str);
    newList->next = hashTable->table[hashVal];
    hashTable->table[hashVal] = newList;

    return 1;
}

void FreeTable(HashSet *hashTable)
{
    int i;
    Node *list, *temp;

    if (hashTable == nullptr)
        return;

    for (i = 0; i < hashTable->size; i++)
    {
        list = hashTable->table[i];
        while (list != nullptr)
        {
            temp = list;
            list = list->next;
            delete temp;
        }
    }

    free(hashTable->table);
    free(hashTable);
}

int main()
{
    HashSet *hashTable = CreateHashSet(5);
    assert(hashTable != nullptr);

    const std::string str = "Jupiter";
    AddString(hashTable, str.c_str());
    AddString(hashTable, "Venus");
    AddString(hashTable, "Mercury");

    Node *n = Lookup(hashTable, "Earth");
    if (n)
    {
        std::cout << "Name found is " << n->str;
    }
    else
    {
        std::cout << "Name not found \n";
    }

    FreeTable(hashTable);

    return 0;
}
