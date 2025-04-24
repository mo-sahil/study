#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> graph, int start)
{
    vector<bool> visited(graph.size(), false);
    stack<int> st;
    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            cout << node << " ";
            visited[node] = true;
        }

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                st.push(neighbor);
            }
        }
    }
}

int main()
{
    int n, v;

    cin >> n >> v;

    vector<vector<int>> graph(n);

    for (int i = 0; i < v; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "DFS Traversal: ";
    dfs(graph, 0);
}