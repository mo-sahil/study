#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;

    for(int i = 2; i<n; i++)
        if(n%i == 0) return false;

    return true;
}

bool isPrimeBetter(int n) {
    if(n < 2) return false;

    for(int i = 2; i<=sqrt(n); i++)
        if(n%i == 0) return false;

    return true;
}

bool isPrimeOptimal(int n) {
    if(n < 2) return false;
    if(n <= 3) return true;

    if(n%2 == 0 || n%3 == 0) return false;

    for(int i = 5; i <= sqrt(n); i+=6) 
        if(n%i == 0 || n%(i+2) == 0) 
            return false;
    
    return true;
}

int main() {
    int n;
    cout << "Enter upper bound: ";
    cin >> n;
    cout << "Prime numbers from 1 to " << n << ":" << endl;
    for(int i = 1; i<=n; i++) {
        if(isPrimeOptimal(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}