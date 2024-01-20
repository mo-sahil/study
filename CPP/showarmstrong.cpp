#include<iostream>
using namespace std;

bool isarmstrong(int number)
{
    int armstrong=0, remainder, temp1, temp2, result=1, digit=0;

    temp1 = number;
    temp2 = number;

    while (temp1>0)
    {
        temp1 /= 10;
        digit++;
    }

    while (temp2 > 0)
    {
        remainder = temp2 % 10;
        for (int i=0; i<digit; i++)
        {
            result *= remainder;
        }
        armstrong += result;
        temp2 /= 10;
        result = 1;
    }

    if (number == armstrong) return true;
    else return false;
}

void printarmstrong(int start, int end)
{
    for (int i=start; i<=end; i++)
    {
        if (isarmstrong(i)) cout << i << "\t ";
    }
}

int main()
{
    int start, end;

    cout << "Enter lower limit and upper limit respectively: ";
    cin >> start >> end;

    printarmstrong(start, end);

    return 0;
}