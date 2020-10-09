#include <iostream>
#include <vector>
#include <list>
#include <set>

using WeightedEdge = std::list<std::pair<int, int>>;

// Vertex and weight pair for every edge
WeightedEdge *adj;

void AddEdge(WeightedEdge adj[], int u, int v, int w)
{
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
}

void ShortestPath(int source, int verteciesCount)
{
    std::set<std::pair<int, int>> setds;
    std::vector<int> dist(verteciesCount, std::numeric_limits<int>::max());

    setds.insert(std::make_pair(0, source));
    dist[source] = 0;

    while (!setds.empty())
    {
        std::pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        for (const auto &p : adj[tmp.second] /* u */)
        {
            int v = (*p).first;
            int weight = (*p).second;

            if (dist[v] > dist[adj[tmp.second]] + weight)
            {
                if (dist[v] != std::numeric_limits<int>::max())
                {
                    setds.erase(setds.find(std::make_pair(dist[v], v)));
                }

                dist[v] = dist[adj[tmp.second]] + weight;
                setds.insert(std::make_pair(dist[v], v));
            }
        }
    }
}
