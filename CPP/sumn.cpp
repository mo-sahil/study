#include<iostream>
using namespace std;

int main()
{
    int num, sum = 0;

    cout << "Enter number: ";
    cin >> num;
    if (num > 0)
    {
        for (int i = 1; i <= num; i++)
        {
            sum += i;
        }
        cout << "Sum till " << num << " = " << sum << endl;
    }
    else
    {
        cout << "Enter natural number greater than 0.";
    }
    

    return 0;
}