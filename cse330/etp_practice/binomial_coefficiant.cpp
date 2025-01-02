#include <iostream>
using namespace std;

// Function to calculate binomial coefficient recursively
int binomialCoeffRecursive(int n, int k) {
    // Base cases
    if (k == 0 || k == n) return 1;

    // Recursive relation: C(n, k) = C(n-1, k-1) + C(n-1, k)
    return binomialCoeffRecursive(n - 1, k - 1) + binomialCoeffRecursive(n - 1, k);
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    int result = binomialCoeffRecursive(n, k);
    cout << "Binomial Coefficient C(" << n << ", " << k << ") is: " << result << endl;

    return 0;
}
