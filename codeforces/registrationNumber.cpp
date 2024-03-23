#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    unordered_map<string, int> mp;
    for(int i = 0; i<n; i++) {
        cin >> str;
        if(mp[str] == 0) {
            cout << "OK" << endl;
            mp[str]++;
        } else {
            cout << str + to_string(mp[str]) << endl;
            mp[str]++;
        }
    }
}