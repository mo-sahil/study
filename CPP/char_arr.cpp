#include<iostream>
using namespace std;

int main()
{
    char b[10];
    cin >> b;
    cout << b << endl;

    int n=0;

    for(int i=0; b[i]!='\0'; i++)
    {
        n++;
    }

    cout << "length: " << n;
    
    return 0;
}