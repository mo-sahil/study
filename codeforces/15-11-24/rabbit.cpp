#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> tree[n + 1];
        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            tree[parent].push_back(i);
        }

        // BFS to find the maximum depth of the tree
        queue<int> q;
        q.push(1);
        int maxDepth = 0;

        while (!q.empty()) {
            int size = q.size();
            maxDepth++;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                for (int child : tree[node]) {
                    q.push(child);
                }
            }
        }

        // Calculate the minimum depth of the perfect binary tree
        int minDepth = 0;
        while ((1 << minDepth) - 1 < n) {
            minDepth++;
        }

        cout << minDepth << "\n";
    }

    return 0;
}