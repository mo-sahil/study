#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(int n){
    string s = to_string(n);
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    
    for(int a0=0; a0<T; a0++){
        int n;
        cin >> n;
        
        for(long i=999; i>99; i--){
            for(long j = i; i*j<n; j--){
                long k = i*j;
                if(k < n && isPalindrome(k)){
                    cout << k << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}
