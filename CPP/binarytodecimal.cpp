#include<iostream>
#include<cmath>
using namespace std;

int convert(long long bin)
{
    int rem, dec=0, i=0;

    while (bin>0)
    {
        rem = bin%10;
        dec += rem * pow(2,i); 
        i++;
        bin /= 10;
    }

    return dec;
}

int main()
{
    long long bin;

    cout << "Enter a binary nmumber: ";
    cin >> bin;

    cout << "In Decimal = " << convert(bin);

    return 0;
}