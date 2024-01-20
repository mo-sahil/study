#include <iostream>
using namespace std;

class rectangle{
    public:
        int l;
        int b;

        rectangle(){//default constructor
            l = 0;
            b = 0;
        }

        rectangle(int x, int y){//parameterised constructor
            l = x;
            b = y;
        }

        rectangle(rectangle &r){//copy constructor
            l = r.l;
            b = r.b;
        }
        ~rectangle(){//destructor
            cout << "destructor function is called" << endl;
        }
};

int main(){
    rectangle r1;
    rectangle r2(2, 3);
    rectangle r3 = r2;
    cout << r1.l << " " << r1.b << endl;
    cout << r2.l << " " << r2.b << endl;
    cout << r3.l << " " << r3.b << endl;
    return 0;
}