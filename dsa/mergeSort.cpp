#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    int i1 = 0, i2 = 0;
    k = s;

    while (i1 < len1 && i2 < len2)
    {
        if (first[i1] <= second[i2])
        {
            arr[k++] = first[i1++];
        }
        else
            arr[k++] = second[i2++];
    }

    while (i1 < len1)
    {
        arr[k++] = first[i1++];
    }

    while (i2 < len2)
    {
        arr[k++] = second[i2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {4, 2, 1, 3, 5, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i : arr)
        cout << i << " ";

    return 0;
}