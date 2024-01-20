#include<iostream>
using namespace std;

int main()
{
    int side;

    cout << "Enter length of side: ";
    cin >> side;

    for (int i=1; i<=side; i++)
    {
        for (int j=1; j<=i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}