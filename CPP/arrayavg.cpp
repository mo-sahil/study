#include<iostream>
using namespace std;

int main()
{
    int size, sum=0;

    cout << "Enter size of array: ";
    cin >> size;

    int array[size];
    for (int i=0; i<size; i++)
    {
        cin >> array[i];
        sum += array[i];
    }

    float average = (float) sum/size;
    cout << "Average = " << average;

    return 0;
}