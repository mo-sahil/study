#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    char op;

    cout << "Enter First Number: ";
    cin >> num1;

    cout << "Enter Second Number: ";
    cin >> num2;

    cout << "Enter operator: ";
    cin >> op;

    if (op == '+') cout << num1 + num2;
    else if (op == '-') cout << num1 - num2 << '\n';
    else if (op == '*') cout << num1 * num2 << '\n';
    else if (op == '/') cout << num1 / num2 << '\n';
    else if (op == '%') cout << num1 % num2 << '\n';
    else if (op == '+') cout << "Invalid Operator" << '\n';

    return 0;
}