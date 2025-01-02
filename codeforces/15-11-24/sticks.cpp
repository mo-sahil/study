#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSort(vector<int>& count) {
    int n = count.size();
    int c = 0;
    for (int i = 1; i < n; ++i) {
        if (count[i] < count[i-1] && count[i-1]-count[i] == 1) {
            swap(count[i],count[i-1]);
            c++;
        }
    } 

    bool sorted = true;
    for(int i = 1; i<n; i++){
        if(count[i-1] > count[i]){
            sorted = false;
            break;
        }
    }

    if(sorted) return true;
    
    if (c == 0) return false;
    return canSort(count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        
        if (canSort(p)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
