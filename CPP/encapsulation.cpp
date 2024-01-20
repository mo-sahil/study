#include <iostream>
using namespace std;

class abc{
    int x;

    public:
        void set(int n){
            x = n;
        }

        int get(){
            return x;
        }
};

int main(){
    abc obj;
    obj.set(56);
    
    cout << obj.get() << endl;
    
    return 0;
}