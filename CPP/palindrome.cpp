#include<iostream>
using namespace std;

int main()
{
    int number, reverse=0, remainder, temp;

    cout << "Enter a positive number: ";
    cin >> number;

    temp = number;

    while (temp > 0)
    {
        remainder = temp % 10;
        reverse = reverse * 10 + remainder;
        temp /= 10;
    }

    if (number == reverse)
    {
        cout << number << " is a palindrome number.";
    }
    else
    {
        cout << number << " is not a palindrome number.";
    }

    return 0;
}