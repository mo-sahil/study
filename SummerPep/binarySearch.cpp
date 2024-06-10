#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0, end =size - 1;
    int mid = start + (end-start)/2;

    while(start <= end) {
        if(arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else start = mid + 1;

        mid = start + (end-start)/2;
    }

    return -1;
}

int main(){
    int arr[] = {1,2,4,6,7,8, 9};

    int key = 4;

    int found = binarySearch(arr,7, key);
    cout << key << " is " << "present at index "  << found << endl;
}