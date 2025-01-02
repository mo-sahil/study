#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {3, 1, 4, 1, 2};

    int sum = 0;

    for(int i : arr) sum += i;

    int lsum = 0;
    for(int i = 0; i<arr.size(); i++){
        lsum += arr[i];
        sum -= arr[i];

        if(lsum > sum && i != arr.size()-1) {
            cout << "Index : " << i << endl;
            exit(0);
        }
    }

    cout << "Not Possible" << endl;

    return 0;
}