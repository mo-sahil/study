#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int l_arr[n1], r_arr[n2];

    for(int i = 0; i<n1; i++) {
        l_arr[i] = arr[l + i];
    }

    for(int i = 0; i<n2; i++) {
        r_arr[i] = arr[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(l_arr[i] <= r_arr[j]) {
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }

    while(i<n1) arr[k++] = l_arr[i++];
    while(j<n2) arr[k++] = r_arr[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l >= r) return;

    int m = l + (r-l)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main(){
    int arr[] = {3,4,2,5,3,6,1,5};
    mergeSort(arr,0,7);

    for(int i = 0; i<8; i++){
        cout << arr[i] << " ";
    }
}