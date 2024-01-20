#include <iostream>
using namespace std;

class fruits{
    public:
        string name;
        string colour;
};

int main(){
    fruits apple;
    apple.name = "Apple";
    apple.colour = "Red";

    cout << apple.name << " - " << apple.colour << endl;

    fruits *mango = new fruits();
    mango->name = "Mango";
    mango->colour = "yellow";

    cout << mango->name << " - " << mango->colour << endl;

    return 0;
}