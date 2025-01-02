#include <iostream>
#include <cmath>
using namespace std;

void primeFactors(int n) {
    if(n%2==0)
        cout << 2 << " ";

    while (n % 2 == 0)
        n /= 2;

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        if(n % i == 0) cout << i << " ";
        while (n % i == 0)
            n /= i;
    }

    if (n > 2)
        cout << n << " ";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Prime factors of " << n << " are: ";
    primeFactors(n);
    cout << endl;
    return 0;
}