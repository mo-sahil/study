#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of Longest Common Subsequence
int longestCommonSubsequence(string A, string B) {
    int m = A.length();
    int n = B.length();

    // Create a DP table to store the lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take the maximum of excluding one character
            }
        }
    }

    // The length of LCS is stored in dp[m][n]
    return dp[m][n];
}

int main() {
    string A = "ABCBDAB";
    string B = "BDCAB";

    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(A, B) << endl;
    return 0;
}
