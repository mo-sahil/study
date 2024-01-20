#include<iostream>
using namespace std;

int main()
{
    int num1, num2, temp;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Numbers you entered are " << num1 << " and " << num2 << endl;

    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "Numbers after swap are " << num1 << " and " << num2 << endl;

    return 0;
}