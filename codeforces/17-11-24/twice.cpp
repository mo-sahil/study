#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++) {
            int el;
            cin >> el;
            mp[el]++;
        }

        int score = 0;

        for(auto i : mp){
            score += (i.second / 2);
        }

        cout << score << endl;
    }
    return 0;
}