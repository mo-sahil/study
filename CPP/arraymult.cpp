#include<iostream>
using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter number of rows in first matrix: ";
    cin >> r1;

    cout << "Enter number of column in first matrix: ";
    cin >> c1;

    cout << "Enter number of rows in second matrix: ";
    cin >> r2;

    cout << "Enter number of column in second matrix: ";
    cin >> c2;

    if (c1 != r2) 
        cout << "Number of columns in first matrix must be equal to number of rows in the second matrix.";

    int matrix1[r1][c1], matrix2[r2][c2], resultmatrix[r1][c2];

    cout << "Enter elements in the first matrix: " << endl;
    for (int i=0; i<r1; i++)
        for (int j=0; j<c1; j++)
            cin >> matrix1[i][j];    

    cout << "Enter elements in the second matrix: " << endl;
    for (int i=0; i<r2; i++)
        for (int j=0; j<c2; j++)
            cin >> matrix2[i][j];

    for (int i=0; i<r1; i++)
        for (int j=0; j<c2; j++)
            resultmatrix[i][j] = 0;

    for (int i=0; i<r1; i++)
        for (int j=0; j<c2; j++)
            for (int k=0; k<c1; k++)
                resultmatrix[i][j] += matrix1[i][k] * matrix2[k][j];

    cout << "Resultant matrix: " << endl;
    for (int i=0; i<r1; i++)
    {
        for (int j=0; j<c2; j++)
        {
            cout << resultmatrix[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}