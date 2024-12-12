#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int x = 0, y = 1;

    for(; y * y <= n; y++){
        if(sqrt(n + y*y) == (int)sqrt(n + y*y)){
            x = sqrt(n + y*y);
            break;
        }
    }

    cout << x+y << " & " << x - y << endl;
}