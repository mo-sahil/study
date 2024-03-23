#include<iostream>
using namespace std;

int main() {
    int n, h, w;
    cin >> n >> h >> w;

    int mx = max(h,w);
    int eh, ew, mn;
    for(int i = 0; i<n; i++) {
        cin >> eh >> ew;
        mn = min(eh, ew);
        cout << mn/mx << endl;
    }
}