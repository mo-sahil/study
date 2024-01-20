#include<iostream>
using namespace std;

int main()
{
    int number, reverse=0, temp, remainder;

    cout << "Enter number: ";
    cin >> number;

    temp = number;

    while (temp>0)
    {
        remainder = temp%10;
        reverse = reverse * 10 + remainder;
        temp /= 10; 
    }

    cout << "Reverse of " << number << " is " << reverse;

    return 0;
}