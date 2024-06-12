#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    for(int i = 0; i<str.size()/2; i++) {
        if(str[i] != str[str.size()-i-1]) {
            cout << "Not Palindrome" << endl;
            return 0;
        }
    }

    cout << "Palindrome" << endl;

    return 0;
}