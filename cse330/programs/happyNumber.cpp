#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> mp;

int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int t = n % 10;
        sum += t * t;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    if (n == 1) return true;
    if (mp.find(n) != mp.end()) return false;

    mp.insert(n);
    return isHappy(getNext(n));
}

int main() {
    int n;
    cin >> n;

    if (isHappy(n)) {
        cout << "Happy" << endl;
    } else {
        cout << "Not Happy" << endl;
    }

    return 0;
}   