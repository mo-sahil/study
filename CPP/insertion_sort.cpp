#include<iostream>
using namespace std;

void selection_sort(int * array, int n)
{
    int key,j;
    for(int i=1; i<n; i++)
    {
        key = array[i];
        j = i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j -= 1;
        }
        array[j+1] = key; 
    }
}

void print_array(int * array, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int array[n];
    for(int i=0; i<n; i++)
    {
        cin >> array[i];
    }

    selection_sort(array, n);
    print_array(array, n);

    return 0;
}
