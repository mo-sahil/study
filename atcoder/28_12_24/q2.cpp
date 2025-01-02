#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int i = 0, n = s.size(), count = 0;

    while(i<n){
        if(s[i] != '0'){
            count++;
            i++;
        } else {
            int count_0 = 0;
            while(i < n && s[i] == '0'){
                count_0++;
                i++;
            }

            count += count_0/2 + count_0%2;
        }
    }

    cout << count << endl;
    
    return 0;
}