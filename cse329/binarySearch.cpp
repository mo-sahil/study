#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *arr, int size, int target){
    int start = 0;
    int end = size;
    cout << end << endl;

    while(start < end){
        int mid = start + (end - start)/2;

        if(arr[mid] == target) return mid;
        else if (arr[mid] < target) start = mid+1;
        else end = mid - 1;
    }

    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;

    int target = 7;

    int res = binarySearch(arr, size, target);

    if(res != -1) cout << target << " is at index : " << res << endl;
    else cout << target << " is not present in the array" << endl;

    return 0;
}