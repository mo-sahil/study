#include <iostream>
using namespace std;

void reverse(string str)
{
    int size = str.size();
    for(int i=size-1; i>=0; i--)
    {
        cout << str[i];
    }
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    reverse(str);

    return 0;
}