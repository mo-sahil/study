#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int unboundedKnapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= W; i++) {
        for (int j = 0; j < n; j++) {
            if (weights[j] <= i) {
                dp[i] = max(dp[i], dp[i - weights[j]] + values[j]);
            }
        }
    }
    
    return dp[W];
}

int main() {
    vector<int> weights = {2, 3, 4};
    vector<int> values = {3, 5, 7};
    int W = 8;
    int n = weights.size();

    int result = unboundedKnapsack(W, weights, values, n);
    cout << "Maximum value: " << result << endl;

    return 0;
}
