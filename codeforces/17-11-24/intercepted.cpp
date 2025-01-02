#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    int t; 
    cin >> t;
    
    while (t--) {
        int k;
        cin >> k;
        
        vector<int> a(k);
        unordered_set<int> elements;

        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            elements.insert(a[i]);
        }

        int size = k - 2;
        
        for (int n = 1; n * n <= k; ++n) {
            if (size % n == 0) {
                int m = size / n; 
                if (elements.count(n) && elements.count(m)) {
                    cout << n << " " << m << endl;
                    break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
