#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(int n, int k, vector<int>& stalls, int dist) {
        int stall = stalls[0], count = 1;
        
        for(int i = 0; i<n; i++) {
            if(stalls[i] - stall >= dist) {
                count++;
                stall = stalls[i];
            }
            
            if(count == k) return true;
        }
        
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        
        int high = stalls[n-1] - stalls[0], low = 1;
        
        while(low<=high) {
            int mid = (low+high)/2;
            if(possible(n,k,stalls,mid)) low = mid + 1;
            else high = mid - 1;
        }
        
        return high;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        
        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

    }

    return 0;
}