#include <iostream>
#include <string>
using namespace std;

bool isOneEditAway(string S, string T) {
    int lenS = S.length();
    int lenT = T.length();

    if (abs(lenS - lenT) > 1) return false;

    if (lenS == lenT) {
        int differences = 0;
        for (int i = 0; i < lenS; ++i) {
            if (S[i] != T[i]) differences++;
            if (differences > 1) return false;
        }
        return true;
    }

    if (lenS + 1 == lenT) {
        int i = 0, j = 0;
        while (i < lenS && j < lenT) {
            if (S[i] != T[j]) {
                j++;
                if (i != j - 1) return false;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }

    if (lenS - 1 == lenT) {
        int i = 0, j = 0;
        while (i < lenS && j < lenT) {
            if (S[i] != T[j]) {
                i++;
                if (i - 1 != j) return false;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }

    return false;
}

int main() {
    int k;
    string S, T;
    cin >> k >> S >> T;

    if (isOneEditAway(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}