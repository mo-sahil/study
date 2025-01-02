#include<iostream>
using namespace std;

void fun(int n){
    if(n > 2) {
        fun(n-1);
        fun(n-2);
        fun(n-3);
    }

    cout << n << " ";
}

int main(){
    int n;
    cin >> n;

    fun(n);
    
    return 0;
}