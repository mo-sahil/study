#include<iostream>
using namespace std;

bool isprime(int number)
{
    if (number < 2) return false;
    for (int i=2; i<number; i++)
    {
        if (number % i==0) return false;
    }

    return true;
}

void printprime(int start, int end)
{
    cout << "Prime numbers between " << start << " and " << end << " are:" << endl;
    for (int i=start; i<=end; i++)
    {
        if (isprime(i)) cout << i << "\t ";
    }
}

int main()
{
    int start, end;

    cout << "Enter lower limit and upper limit respectively: ";
    cin >> start >> end;

    printprime(start, end);

    return 0;
}