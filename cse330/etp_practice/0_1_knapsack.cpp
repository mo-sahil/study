#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    // Create a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w]; // Exclude the current item
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int result = knapsack(W, weights, values, n);
    cout << "The maximum value that can be obtained: " << result << endl;

    return 0;
}
