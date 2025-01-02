#include <bits/stdc++.h>
using namespace std;

void simpleSieve(int limit, vector<int>& prime) {
    vector<bool> mark(limit + 1, true);
    for (int p = 2; p * p <= limit; p++) 
        if (mark[p]) 
            for (int i = p * p; i <= limit; i += p)
                mark[i] = false;
                
    for (int p = 2; p <= limit; p++) 
        if (mark[p]) 
            prime.push_back(p);
}

void segmentedSieve(int l, int r) {
    int limit = floor(sqrt(r)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime);

    vector<bool> mark(r - l + 1, true);

    for (int i : prime) {
        int lowLim = max(i * i, (l + i - 1) / i * i);
        for (int j = lowLim; j <= r; j += i)
            mark[j - l] = false;
    }

    for (int i = max(l, 2); i <= r; i++) {
        if (mark[i - l])
            cout << i << " ";
    }
}

int main() {
    int l, r;
    cout << "Enter range: " << endl << "l: ";
    cin >> l;
    cout << "r: ";
    cin >> r;

    segmentedSieve(l, r);

    return 0;
}