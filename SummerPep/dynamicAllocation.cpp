#include<iostream>
using namespace std;

int main() {
    int* a = new int(10);
    cout << endl << "a ---> " << a << endl << endl;
    
    cout << endl << "*a ---> " << *a << endl << endl;

    int* arr = new int[10];
    cout << endl << "arr ---> " << arr << endl << endl;
    
    cout << endl << "*arr ---> " << *arr << endl << endl;

    char arr1[] = "Sahil";
    cout << endl << "arr1 ---> " << arr1 << endl << endl;
    
    cout << endl << "*arr1 ---> " << *arr1 << endl << endl;
}
