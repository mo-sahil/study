#include<bits/stdc++.h>
using namespace std;

int min(int arr[], int size, int s) {
    int min = INT_MAX;
    int idx = -1;
    for(int i = s; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
            idx = i;
        }
    }

    return idx;
}

int main() {
    int arr[] = {1,2,4,5,3,2,5,4};
    int size = sizeof(arr)/sizeof(int);
    for(int i = 0; i<size; i++) {
        int idx = min(arr,size, i);
        swap(arr[i], arr[idx]);
    }

    cout << "Sorted -->";
    for(int i : arr) cout << " " << i;
    cout << endl; 
}