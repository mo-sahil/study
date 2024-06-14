#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start-1;
    for(int j = start; j<end; j++) {
        if(arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

int select(int arr[], int start, int end, int n) {
    if(start == end) {
        return arr[start];
    }

    int pivotIndex = partition(arr, start, end);

    if(n == pivotIndex) {
        return arr[n];
    } else if(n < pivotIndex) {
        return select(arr, start, pivotIndex - 1, n);
    } else {
        return select(arr, pivotIndex + 1, end, n);
    }
}

int main() {
    int arr[] = {1, 3, 2, 4, 10, 12, 11, 8, 9, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 3;

    cout << "nth smallest element: " << select(arr, 0, size-1, n-1);
}
