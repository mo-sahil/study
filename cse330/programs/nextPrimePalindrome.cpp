#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    if(n <= 3) return true;

    if(n%2 == 0 || n%3 == 0) return false;

    for(int i = 5; i*i <= n; i+=6) 
        if(n%i == 0 || n%(i+2) == 0) 
            return false;
    
    return true;
}

bool isPalindrome(int n){
    string s = to_string(n);

    for(int i = 0; i<s.size()/2; i++) if(s[i] != s[s.size()-i-1]) return false;

    return true;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    while(true){
        if (8 <= n && n <= 11){
            cout << "Next Prime Palindrome: " << 11 << endl;
            break;
        } else if (isPrime(n) && isPalindrome(n)) {
            cout << "Next Prime Palindrome: " << n << endl;
            break;
        }
        n+=2;
    }

    return 0;
}