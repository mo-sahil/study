#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *arr, int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) return mid;

        if (arr[start] <= arr[mid]) {
            if (target >= arr[start] && target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (target > arr[mid] && target <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    int arr[] = {6, 7, 1, 2, 3, 4, 5};
    int size = 7;

    int target = 5;

    int res = binarySearch(arr, size, target);

    if(res != -1) cout << target << " is at index : " << res << endl;
    else cout << target << " is not present in the array" << endl;

    return 0;
}