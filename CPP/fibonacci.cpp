#include<iostream>
using namespace std;

int main()
{
    int a=0, b=1, temp=0, num;

    cout << "Enter last limit: ";
    cin >> num;

    while (a < num)
    {
        cout << a << endl;
        temp = b;
        b += a;
        a = temp;
    }

    return 0;
}