#include <bits/stdc++.h>
using namespace std;

int main() {
    string name;
    cin >> name;

    unordered_map<char, int> freq;

    for (char c : name) {
        freq[c]++;
    }

    for (auto& pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}