#include <iostream>
using namespace std;

// Function to calculate the number of ways to tile a 2xN floor
int tilingWays(int n) {
    if (n == 0) return 0; // No floor, no ways
    if (n == 1) return 1; // Only one way: vertical tile
    if (n == 2) return 2; // Two ways: two vertical or two horizontal

    int prev2 = 1, prev1 = 2, curr = 0;

    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2; // Recurrence relation
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() {
    int n;
    cout << "Enter the value of N (length of the floor): ";
    cin >> n;

    cout << "Number of ways to tile a 2x" << n << " floor: " << tilingWays(n) << endl;
    return 0;
}
