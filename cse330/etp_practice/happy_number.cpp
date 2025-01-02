#include <iostream>
#include <unordered_set>
using namespace std;

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = sumOfSquares(n);
    }
    return n == 1;
}

int nextHappyNumber(int n) {
    n++; 
    while (!isHappy(n)) {
        n++;
    }
    return n;
}

int main() {
    int start;
    cout << "Enter the starting number: ";
    cin >> start;
    int result = nextHappyNumber(start);
    cout << "The next happy number is: " << result << endl;
    return 0;
}
