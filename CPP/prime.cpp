#include<iostream>
using namespace std;

int main()
{
    int number, temp=0;

    cout << "Enter a positive number: ";
    cin >> number;

    for (int i=2; i<number; i++)
    {
        if (number % i == 0)
        {
            temp++;
            break;
        }
    }
    if (temp)
    {
        cout << number << " is not a prime number";
    }
    else if (number == 1)
    {
        cout << number << " is not a prime number";
    }
    else if (number == 2)
    {
        cout << number << " is a prime number";
    }
    else
    {
        cout << number << " is a prime number";
    }
    

    return 0;
}