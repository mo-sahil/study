#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_operations(vector<int>& h) {
    int n = h.size();
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; ++i) {
        if (h[i] >= h[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    
    return n - *max_element(dp.begin(), dp.end());
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        
        cout << min_operations(h) << endl;
    }
    
    return 0;
}