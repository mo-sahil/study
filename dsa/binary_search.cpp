#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements in array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in increasing order: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: " << endl;
    cin >> key;

    int found = binarySearch(arr, n, key);

    if (found == -1)
    {
        cout << "Element not found in array" << endl;
    }
    else
    {
        cout << "Element is at " << found << " index" << endl;
    }

    return 0;
}