#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 4, 10, 12, 11, 8, 9, 5, 2, 4, 3 , 11, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    int min = INT_MAX, max = INT_MIN;
    for(int i : arr) {
        if(i < min) min = i;
        if(i > max) max = i;
    }

    int range = max - min + 1;
    int count[range] = {0};

    for(int i = 0; i<size; i++) {
        count[arr[i] - min]++;
    }  

    for(int i = 1; i<range; i++) {
        count[i] += count[i-1];
    }

    int sorted[size];

    for(int i = size-1; i>=0; i--) {
        sorted[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }   

    for(int i = 0; i<size; i++) {
        arr[i] = sorted[i];
    }

    cout << "Sorted array:";
    for(int i : arr) cout << " " << i;

    return 0;
}