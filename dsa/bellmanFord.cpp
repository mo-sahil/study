#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int V = 6;
    int E = 9;

    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 6});
    adj[0].push_back({2, 4});
    adj[0].push_back({3, 5});
    adj[1].push_back({4, -1});
    adj[2].push_back({4, 3});
    adj[2].push_back({1, -2});
    adj[3].push_back({5, -1});
    adj[3].push_back({2, -2});
    adj[4].push_back({5, 3});

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        bool changed = false;
        for (int u = 0; u < V; u++)
        {
            for (auto edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    changed = true;
                    dist[v] = dist[u] + weight;
                }
            }
        }

        if (!changed)
            break;
    }

    for (int u = 0; u < V; u++)
    {
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                cout << "Graph contains negative weight cycle" << endl;
                return 0;
            }
        }
    }

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }

    return 0;
}
