#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to calculate edit distance
int editDistance(string A, string B) {
    int m = A.length();
    int n = B.length();

    // Create a DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i; // Deletions
    for (int j = 0; j <= n; j++) dp[0][j] = j; // Insertions

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}); // Min of deletion, insertion, substitution
            }
        }
    }

    return dp[m][n];
}

int main() {
    string A, B;
    cout << "Enter first string: ";
    cin >> A;
    cout << "Enter second string: ";
    cin >> B;

    cout << "Minimum edit distance: " << editDistance(A, B) << endl;
    return 0;
}
