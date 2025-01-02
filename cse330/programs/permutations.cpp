#include <iostream>

using namespace std;

void permutations(string str, int idx){
    if(idx == str.size()){
        cout << str << " ";
        return;
    }

    for(int i = idx; i<str.size(); i++){
        swap(str[i], str[idx]);
        permutations(str, idx+1);
        swap(str[i], str[idx]);
    }
}

int main(){
    string str;
    cin >> str;

    cout << "Permutations: " << endl;
    permutations(str, 0);

    return 0;
}


