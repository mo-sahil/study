#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isCryptSolution(vector<string>& crypt, vector<vector<char>>& solution) {
    vector<long long> values;
    for (const auto& word : crypt) {
        long long value = 0;
        for (const auto& ch : word) {
            for (const auto& pair : solution) {
                if (pair[0] == ch) {
                    value = value * 10 + (pair[1] - '0');
                    break;
                }
            }
        }
        values.push_back(value);
    }
    
    if (values[0] + values[1] != values[2]) {
        return false;
    }
    
    // Check for leading zeros
    for (const auto& word : crypt) {
        if (word.length() > 1 && solution[word[0] - 'A'][1] == '0') {
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<string> crypt;
    vector<vector<char>> solution = {
        {'O', '0'},
        {'M', '1'},
        {'Y', '2'},
        {'E', '5'},
        {'N', '6'},
        {'D', '7'},
        {'R', '8'},
        {'S', '9'}
    };
    
    // Get user input for crypt arithmetic problem
    cout << "Enter the crypt arithmetic problem:" << endl;
    for (int i = 0; i < 3; i++) {
        string word;
        cout << "Enter word " << i + 1 << ": ";
        cin >> word;
        crypt.push_back(word);
    }
    
    // Check if the solution is valid
    if (isCryptSolution(crypt, solution)) {
        cout << "The solution is valid." << endl;
    } else {
        cout << "The solution is invalid." << endl;
    }
    
    return 0;
}
