#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool topoSort(int numCourses, vector<vector<int>> &prerequisites, vector<int> &result)
{
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    for (auto &pre : prerequisites)
    {
        adj[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return result.size() == numCourses;
}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}}; //{{2, 0}, {3, 0}, {1, 2}, {1, 3}, {4, 2}, {5, 3}, {5, 4}};

    vector<int> order;
    if (topoSort(numCourses, prerequisites, order))
    {
        cout << "Order of courses: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "A cycle exists. It is not possible to complete all courses." << endl;
    }

    return 0;
}
