#include <bits/stdc++.h>
using namespace std;

set<int> primes;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void fermatsFactors(int n) {
    if (n <= 1) return;
    if (isPrime(n)) {
        primes.insert(n);
        return;
    }

    double x;
    int y;

    for (y = 1; y * y <= n; y++) {
        x = sqrt(n + y * y);
        if (x == floor(x)) break;
    }

    int a = (int)x;
    int b = y;

    fermatsFactors(a - b);
    fermatsFactors(a + b);
}

int main() {
    int n = 3009; // Example number
    fermatsFactors(n);

    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}