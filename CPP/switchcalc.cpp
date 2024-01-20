#include<iostream>
using namespace std;

int main()
{
    int num1, num2;
    char op;

    cout << "Enter two number and operator respectively: ";
    cin >> num1 >> num2 >> op;

    switch (op)
    {
    case '+':
        cout << num1 + num2 << endl;
        break;
    
    case '-':
        cout << num1 - num2 << endl;
        break;

    case '*':
        cout << num1 * num2 << endl;
        break;
    case '/':
        cout << num1 / num2 << endl;
        break;

    case '%':
        cout << num1 % num2 << endl;
        break;

    default:
    cout << "Enter valid operator";
        break;
    }

    return 0;
}