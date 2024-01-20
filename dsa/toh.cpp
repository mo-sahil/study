#include <iostream>
using namespace std;

void TOH(int n, char source, char aux, char des){
    if(n == 1){
        cout << "Moving disk " << n << " from " << source << " to " << des << endl;
        return;
    }

    TOH(n-1, source, des, aux);
    cout << "Moving disk " << n << " from " << source << " to " << des << endl;
    TOH(n-1, aux, source, des);
}

int main(){
    int n;
    cout << "Enter no of disks: ";
    cin >> n;

    TOH(n, 'A', 'B', 'C');

    return 0;
}