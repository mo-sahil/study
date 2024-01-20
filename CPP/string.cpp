#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fname = "Mo";
    string lname = " Sahil";
    string fullname = fname.append(lname);
    cout << fullname;
    return 0;
}