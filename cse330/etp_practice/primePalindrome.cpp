#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPalindrome(int n) {
    string s = to_string(n);
    string reversed_s = string(s.rbegin(), s.rend());
    return s == reversed_s;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int nextPrimePalindrome(int n) {
    while (true) {
        n++;
        if (isPalindrome(n) && isPrime(n)) {
            return n;
        }
    }
}

int main() {
    int start;
    cout << "Enter the starting number: ";
    cin >> start;
    int result = nextPrimePalindrome(start);
    cout << "The next prime palindrome is: " << result << endl;
    return 0;
}
