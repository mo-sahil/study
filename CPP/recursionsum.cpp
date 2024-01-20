#include<iostream>
using namespace std;

int sum(int number)
{
    if (number==1)
        return 1;
    else
        return number + sum(number-1);
}

int main()
{
    int num;

    cout << "Enter a positive number: ";
    cin >> num;

    cout << "Sum = " << sum(num);

    return 0;
}