#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter upper bound: ";
    cin >> n;

    int arr[n+1];
    arr[0] = 0;
    arr[1] = 0;

    for(int i = 2; i<=n; i++) {
        arr[i] = i;
    }

    for(int i = 2; i*i<=n; i++){
        if(arr[i] != 0) {
            for(int j = i*i; j<=n; j+=i){
                arr[j] = 0;
            }
        }
    }

    cout << "Prime numbers from 2 to " << n << ": ";
    for(int i : arr){
        if(i) cout << i << " ";
    }
}