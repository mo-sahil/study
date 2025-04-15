#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> graph[4];
    graph[0].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({3, 4});
    graph[3].push_back({1, 1});

    const int INF = 1e9;
    int dist[4];
    bool visited[4] = {false};

    fill(dist, dist + 4, INF);
    dist[0] = 0;

    for (int i = 0; i < 4; i++)
    {
        int u = -1;

        for (int j = 0; j < 4; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        if (dist[u] == INF)
            break;

        visited[u] = true;

        for (auto edge : graph[u])
        {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "Distance to node " << i << ": " << dist[i] << endl;
    }
}