#include <iostream>
using namespace std;

int unique(int arr[], int size) {
    int start = 0, end = size - 1;
    int mid = start + (end-start)/2;

    while(start < end) {
        if(mid%2) {
            if(arr[mid] == arr[mid - 1]) start = mid + 1;
            else end = mid;
        } else {
            if(arr[mid] == arr[mid + 1]) start = mid + 2;
            else end = mid;
        }
        mid = start + (end - start)/2;
    }

    return arr[mid];
}

int main() {
    int arr[] = {3, 3, 2, 2, 1, 9, 9, 4, 4, 5, 5};

    int size = 11;

    cout << "Unique --> " << unique(arr, size) << endl;
}