#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool BFS(int start, vector<vector<int>> &graph, vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph, int n)
{
    vector<int> color(n, -1);

    for (int start = 0; start < n; ++start)
    {
        if (color[start] == -1)
        {
            if (!BFS(start, graph, color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipartite(graph, n))
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}