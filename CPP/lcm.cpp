#include<iostream>
using namespace std;

int main()
{
    int num1, num2, lcm=1, hcf=1;

    cout << "Enter numbers: ";
    cin >> num1 >> num2;

    for (int i=2; i<=num1; i++)
    {
        if ((num1%i==0) && (num2%i==0))
        {
            hcf = i;
        }
    }

    lcm = (num1*num2)/hcf;

    cout << "LCM of " << num1 << " and " << num2 << " is " << lcm;

    return 0;
}