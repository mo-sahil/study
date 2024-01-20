#include<iostream>
using namespace std;

int Power(int number, int power)
{
    int num=1;
    for (int i=1; i<=power; i++)
    {
        num *= number;
    }
    return num;
}

int main()
{
    int number, power;

    cout << "Enter number and power: ";
    cin >> number >> power;

    cout << number << " to the power " << power << " = " << Power(number, power);

    return 0;
}