#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    if(n <= 3) return true;

    if(n%2 == 0 || n%3 == 0) return false;

    for(int i = 5; i <= sqrt(n); i+=6) 
        if(n%i == 0 || n%(i+2) == 0) 
            return false;
    
    return true;
}

bool isValid(int n, int a) {
    if(!isPrime(n)) return false;

    long long x = pow(a,n-1);
    if((x %= n) == 1) return true;

    return false;
}

int main() {
    cout << isValid(7,3) << endl;
}