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

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int pidx = partition(arr, start, end);
        quickSort(arr, start, pidx-1);
        quickSort(arr, pidx+1, end);
    }
}

int main() {
    int arr[] = {1, 3, 2, 4, 10, 12, 11, 8, 9, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    cout << "Sorted array:";
    for(int i : arr) cout << " " << i;
}