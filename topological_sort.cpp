#include <iostream>
#include <list>
#include <vector>
#include <stack>

void AddEdge(std::vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void TopologicalSortUtils(std::vector<int> adj[], int v, bool visited[], std::stack<int> &st)
{
    visited[v] = true;
    for (const auto &n : adj[v])
    {
        if (!visited[n])
            TopologicalSortUtils(adj, n, visited, st);
    }

    st.push(v); // node without any incoming edges
}

void TopologicalSort(std::vector<int> adj[], int v)
{
    std::stack<int> st;
    bool *visited = new bool[v];
    memset(visited, false, v);

    // Run through all the nodes
    // and visit the neighbors.
    // Push a node on the stack only when
    // there are no unvisited neighbors.
    for (int i = 0; i < v; ++i)
    {
        if (!visited[i])
            TopologicalSortUtils(adj, i, visited, st);
    }

    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    const int vertices = 6;
    std::vector<int> adj[vertices];

    AddEdge(adj, 5, 2);
    AddEdge(adj, 5, 0);
    AddEdge(adj, 4, 0);
    AddEdge(adj, 4, 1);
    AddEdge(adj, 2, 3);
    AddEdge(adj, 3, 1);

    TopologicalSort(adj, vertices);
}