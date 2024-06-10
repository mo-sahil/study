// Write a program to find the second largest element in an array.

#include<iostream>

using namespace std;

int main() {
    int arr[] = {1,3,63,6,7,4,3,9,11};

    int size = sizeof(arr)/sizeof(int);

    int largest = -1, secondLargest = -1;

    for(int i : arr) {
        if(i > secondLargest) {
            if(i > largest) largest = i;
            else secondLargest = i;
        }
    }

    cout << endl << "Largest ---> " << largest << endl << "2nd Largest ---> " << secondLargest << endl << endl;  
}