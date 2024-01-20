#include<iostream>
using namespace std;

bool isprime(int number)
{
    if (number==0 || number==1)
        return false;
    
    for (int i=2; i<number; i++)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int num, k=0;

    cout << "Enter a positive number: ";
    cin >> num;

    for (int i=2; i<num; i++)
    {
        if (isprime(i) && isprime(num-i))
        {
            cout << i << "\t" << num-i << endl;
            k++;
        }
    }

    if (!k)
        cout << "There are no such prime pairs that add up to be " << num << endl;

    return 0;
}