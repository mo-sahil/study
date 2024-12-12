#include <iostream>
using namespace std;

class parent{
    public:
        int x;

    private:
        int y;

    protected:
        int z;
};

class child1: public parent{
    // x will remain public
    // y will not be accessible
    // z will remain protected
};

class child2: private parent{
    // x = private
    // y = inaccessible
    // z = private
};

class child3: protected parent{
    // x = protected
    // y = inaccessible
    // z = protected
};

int main(){
    
     
    return 0;
}