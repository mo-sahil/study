#include<iostream>
using namespace std;

int main()
{
    int side;

    cout << "Enter side length: ";
    cin >> side;

    for (int i=side; i>0; i--)
    {
        for (int j=i; j>0; j--)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}