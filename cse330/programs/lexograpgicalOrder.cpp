#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lexographicalOrder(int a, int n){
    if(a > n) return;

    cout << a << " ";

    for(int i = 0; i<=9; i++){
        if(10*a + i > n) return;
        lexographicalOrder(10*a+i, n);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i<=9; i++)
        lexographicalOrder(i, n);
    return 0;
}