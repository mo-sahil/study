  
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
  
  unordered_map<int, int> mp;
  
  for(int i = 0; i<4; i++){
    int el;
    cin >> el;
    mp[el]++;
  }
  
  for(auto pair : mp) {
    if(pair.second == 3) {
        cout << "Yes" << endl;
        return 0;
    }
    else if(pair.second == 2){
      for(auto i : mp){
        if(i.first != pair.first && i.second == 2){
            cout << "Yes" << endl;
            return 0;
        }
      }
    }
  }
  
  cout << "No" << endl;
  
  return 0;
  
}