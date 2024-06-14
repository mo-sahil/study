#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 4, 10, 12, 11, 8, 9, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int pivot = arr[size-1];

    int i = 0, j = size-1;
    while(i<j) {
        if(arr[i] >= pivot && arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } else if(arr[i] < pivot) {
            i++;
        } else if(arr[j] > pivot) {
            j--;
        }
    }

    cout << "Sorted array:";
    for(int i = 0; i<size; i++) cout << " " << arr[i];

}