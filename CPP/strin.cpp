#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullname;
    cout << "Enter your full name: ";
    getline(cin,fullname);
    cout << "Hello " << fullname << "!";
    return 0;
}