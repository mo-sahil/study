#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        if (n == 1 || n == 2 || n == 3) {
            cout << -1 << endl;
            return;
        }

        // We will use filling numbers 1, 2, 3, ..., m where m = √n
        vector<int> result(n);

        // Start filling the result array
        int index = 0;
        for (int i = 1; i * i <= n; ++i) { // Perfect squares
            for (int j = 0; j < i && index < n; ++j) {
                result[index++] = i; // Fill with filling number i
            }
        }

        // If we filled less than n, we won't have a valid arrangement
        if (index < n) {
            cout << -1 << endl;
        } else {
            for (int filling : result) {
                cout << filling << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
