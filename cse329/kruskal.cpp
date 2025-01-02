#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int city1, city2, cost;
};

bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

int findParent(int city, vector<int>& parent) {
    if (parent[city] != city) {
        parent[city] = findParent(parent[city], parent);
    }
    return parent[city];
}

void unionCities(int city1, int city2, vector<int>& parent, vector<int>& rank) {
    int root1 = findParent(city1, parent);
    int root2 = findParent(city2, parent);

    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

int kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int minCost = 0;
    for (Edge edge : edges) {
        int root1 = findParent(edge.city1, parent);
        int root2 = findParent(edge.city2, parent);

        if (root1 != root2) {
            minCost += edge.cost;
            unionCities(root1, root2, parent, rank);
        }
    }

    return minCost;
}

int main() {
    int n;
    cin >> n;

    vector<Edge> edges(n);
    for (int i = 0; i < n; i++) {
        cin >> edges[i].city1 >> edges[i].city2 >> edges[i].cost;
    }

    int minCost = kruskalMST(edges, n);
    cout << minCost << endl;

    return 0;
}