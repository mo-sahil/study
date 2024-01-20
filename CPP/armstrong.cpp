#include<iostream>
using namespace std;

int main()
{
    int number, armstrong=0, temp1, temp2, remainder, digit=0;

    cout << "Enter a positive number : ";
    cin >> number;

    temp1 = number;
    temp2 = number;

    while (temp1 > 0 )
    {
        temp1 /= 10;
        digit++;
    }

    while (temp2 > 0)
    {
        remainder = temp2 % 10;
        int result = 1;
        for (int i=0; i<digit; i++)
        {
            result *= remainder;
        }
        armstrong += result;
        temp2 /= 10;
    }

    if (number == armstrong)
    {
        cout << number << " is a armstrong number";
    }
    else
    {
        cout << number << " is not a armstrong number";
    }


    return 0;
}