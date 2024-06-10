#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (a.front() == a.back()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            string result(n, 'R');

            // Find the first element that is different from a[0]
            int split_index = 1;
            while (split_index < n && a[split_index] == a[0]) {
                split_index++;
            }

            // Color the remaining elements 'B'
            for (int i = split_index; i < n; ++i) {
                result[i] = 'B';
            }

            cout << result << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
