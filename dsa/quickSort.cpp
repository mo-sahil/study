#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[s], count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    while (s < pivotIndex && e > pivotIndex)
    {
        while (arr[s] < pivot)
            s++;

        while (arr[e] > pivot)
            e--;

        if (s < pivotIndex && e > pivotIndex)
            swap(arr[s], arr[e]);
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {4, 2, 1, 3, 5, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i : arr)
        cout << i << " ";

    return 0;
}