// Implement a function to rotate an array by `k` positions.

#include <iostream>
#include <vector>
using namespace std;

void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    
    auto reverse = [](vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    };


    reverse(arr, 0, n - 1);
    
    reverse(arr, 0, k - 1);
    
    reverse(arr, k, n - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    rotateArray(arr, k);

    cout << "Array after rotation: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}