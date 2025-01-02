#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double waterInGlass(int K, int i, int j) {
    // Create a 2D vector to store water levels, initialized to 0
    vector<vector<double>> dp(i + 1, vector<double>(i + 1, 0.0));

    // Pour water into the first glass
    dp[1][1] = K;

    // Fill the glasses level by level
    for (int level = 1; level < i; level++) {
        for (int pos = 1; pos <= level; pos++) {
            // If there's overflow, distribute the excess water
            if (dp[level][pos] > 1.0) {
                double overflow = dp[level][pos] - 1.0;
                dp[level][pos] = 1.0; // Glass holds at most 1 unit
                dp[level + 1][pos] += overflow / 2.0;
                dp[level + 1][pos + 1] += overflow / 2.0;
            }
        }
    }

    // The result is the minimum of 1 and the water in the desired glass
    return min(1.0, dp[i][j]);
}

int main() {
    int K, i, j;
    cout << "Enter the amount of water (K): ";
    cin >> K;
    cout << "Enter the level (i): ";
    cin >> i;
    cout << "Enter the position (j): ";
    cin >> j;

    double result = waterInGlass(K, i, j);
    cout << fixed << setprecision(6); // For precision output
    cout << "Amount of water in glass (" << i << ", " << j << "): " << result << " units" << endl;
    return 0;
}
