#include<iostream>
using namespace std;

int main()
{
    int divisor, dividend, quotient, remainder;

    cout << "Enter Divisor: ";
    cin >> divisor;

    cout << "Enter Dividend: ";
    cin >> dividend;

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    cout << "Quotient is " << quotient << " and remainder is " << remainder << endl;

    return 0;
}