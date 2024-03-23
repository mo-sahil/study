#include<iostream>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;

    string str;
    for(int i = 0; i<n; i++) {
        cin >> str;
        if(str == "X++" || str == "++X") x++;
        else x--;
    }
    cout << x << endl;
}