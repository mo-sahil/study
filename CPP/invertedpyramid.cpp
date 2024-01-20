#include<iostream>
using namespace std;

int main()
{
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    for (int i=rows,k=0; i>0;i--,k=0)
    {
        for(int space=1; space <= rows - i; space++)
        {
            cout << "  ";
        }
        while (k!=2*i-1)
        {
            cout << "* ";
            k++;
        }
        cout << endl;
    }

    return 0;
}