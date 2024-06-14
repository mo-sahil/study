#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            
            if (prefix.empty()) {
                return "";
            }
        }
    }
    
    return prefix;
}

int main() {
    vector<string> strings = {"Sahil", "Sahas", "Sathi"};
    string commonPrefix = longestCommonPrefix(strings);
    
    cout << "Longest common prefix: " << commonPrefix << endl;
    
    return 0;
}