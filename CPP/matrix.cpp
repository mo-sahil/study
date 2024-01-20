#include<iostream>
using namespace std;

int main()
{
    int rows, column;

    cout << "Enter number of rows and coulmn respectively: ";
    cin >> rows >> column;

    int matrix1[rows][column], matrix2[rows][column], summatrix[rows][column];

    cout << "Enter elements of first matrix: ";
    for (int i=1; i<=rows; i++)
    {
        for (int j=1; j<=column; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements of second matrix: ";
    for (int i=1; i<=rows; i++)
    {
        for (int j=1; j<=column; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    cout << "Resultant matrix:" << endl;
    for (int i=1; i<=rows; i++)
    {
        for (int j=1; j<=column; j++)
        {
            summatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            cout << summatrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}