#include<iostream>
using namespace std;

int main(){
    int t = 0;
    cin >> t;

    while(t--){
        int n = 0;
        cin >> n;

        char arr[n][4];
        for(int i = 0; i<n; i++){
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        }

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<4; j++){
                if(arr[i][j] == '#'){
                    cout << j+1 << " ";
                    break;
                }
            }
        }

        cout << endl;
    }
}