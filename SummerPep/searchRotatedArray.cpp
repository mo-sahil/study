#include <iostream>
using namespace std;

int search(int arr[], int size, int target) {
    int start = 0, end = size - 1;
    int mid = start + (end-start)/2;

    while(start <= end) {
        if(arr[mid] == target) return mid;
        else if (arr[mid] <= arr[end]) {
            if(target > arr[mid] && target <= arr[end]) start = mid + 1;
            else end = mid - 1;
        } else {
            if(target >= arr[start] && target < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        mid = start + (end-start)/2;
    }

    return -1;
}

int main() {
    int arr[] = {7,8,9,10,1,2,3,4};
    
    int size = 8;

    int target = 2;

    int found = search(arr, size, target);

    cout << target << " is ";
    if(found != -1) cout << "found at index " << found << endl;
    else cout << "not found" << endl; 
}