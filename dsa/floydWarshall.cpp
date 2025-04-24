#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;
    vector<vector<int>> graph(n, vector<int>(n, 1e9));

    for (int i = 0; i < v; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] < 1e9 && graph[k][j] < 1e9)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    cout << "Distance matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1e9)
            {
                cout << "INF \t";
            }
            else
            {
                cout << graph[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}