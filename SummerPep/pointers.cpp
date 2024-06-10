#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* b = &a;
    int* c = b;
    cout << a << " " << b << " " << c << " " << *c << endl;
}