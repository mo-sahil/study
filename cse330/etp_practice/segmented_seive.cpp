#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> seive(int n){
    vector<bool> arr(n+1, true);

    for(int i = 2; i*i <= n; i++){
        if(arr[i]){
            for(int j = i*i; j<=n; j+=i){
                arr[j] = false;
            }
        }
    }

    vector<int> ans;
    for(int i = 2; i<=n; i++){
        if(arr[i]) ans.push_back(i);
    }    

    return ans;
}

vector<int> segmented_seive(int l, int r){
    vector<int> primes = seive(sqrt(r));

    vector<bool> ans(r-l+1, true);

    for(int p : primes){
        int start = max(p*p, (l + p - 1) / p * p);
        for(int j = start; j <= r; j += p){
            ans[j-l] = false;
        }
    }

    vector<int> res;
    for(int i = 0; i<r-l+1; i++){
        if(ans[i]) res.push_back(i+l);
    }

    return res;
}

int main(){
    int l , r;
    cin >> l >> r;

    vector<int> primes = segmented_seive(l,r);

    for(int i : primes) cout << i << " ";

    return 0;
}