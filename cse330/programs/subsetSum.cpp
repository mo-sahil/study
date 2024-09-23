#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetSums(vector<int>& arr, int l, int r, int sum, vector<int>& sums) {
    if (l > r) {
        sums.push_back(sum);
        return;
    }
    subsetSums(arr, l + 1, r, sum + arr[l], sums);
    subsetSums(arr, l + 1, r, sum, sums);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> sums;
    subsetSums(arr, 0, arr.size() - 1, 0, sums);
    sort(sums.begin(), sums.end());
    for (int sum : sums) {
        cout << sum << " ";
    }
    return 0;
}