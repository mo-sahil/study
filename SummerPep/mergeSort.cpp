#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int i = start, j = mid + 1, k = 0;
    int merged[end - start + 1];
    while(i<=mid && j<=end) {
        if(arr[i] <= arr[j]) {
            merged[k++] = arr[i++];
        } else {
            merged[k++] = arr[j++];
        }
    }

    while(i<=mid) merged[k++] = arr[i++];
    while(j<=end) merged[k++] = arr[j++];
    
    for(int i = start; i<=end; i++) arr[i] = merged[i-start];
}

void divide(int arr[], int start, int end) {
    if(start < end) {
        int mid = start + (end - start)/2;
        divide(arr, start, mid);
        divide(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {3,2,5,6,3,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    divide(arr, 0, n-1);
    cout << "Sorted array:";
    for(int i = 0; i<n; i++) cout << " " << arr[i];
    return 0;
}
