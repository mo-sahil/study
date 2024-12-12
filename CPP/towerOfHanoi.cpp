#include <iostream>
using namespace std;

void ToH(int n, char source, char aux, char dest){
    if (n==1){
        cout << "Moving disc 1 from " << source << " to " << dest << endl; 
        return;
    }
    ToH(n-1, source, dest, aux);
    cout << "Moving disc " << n << " from " << source << " to " << dest << endl;
    ToH(n-1, source, aux, dest);
}

int main(){
    int n;
    cout << "Enter no of discs: ";
    cin >> n;

    ToH(n, 'A', 'B', 'C');
    
    return 0;
}