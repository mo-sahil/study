#include <iostream>
using namespace std;

class parent{
    public:
        parent(){
            cout << "Parent class" << endl;
        }
};

class child: public parent{
    public:
        child(){
            cout << "child class" << endl;
        }
};

class grand_child: public child{
    public:
        grand_child(){
            cout << "grand child" << endl;
        }
};

int main(){
    grand_child ch;
    
    return 0;
}