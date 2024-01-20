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

int main(){
    child ch;
    
    return 0;
}