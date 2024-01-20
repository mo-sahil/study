#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n < 2)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;

    cout << "enter number: ";
    cin >> n;

    cout << "Factorial of " << n << " is " << factorial(n);

    return 0;
}