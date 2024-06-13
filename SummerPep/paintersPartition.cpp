#include <bits/stdc++.h>
using namespace std;


class Solution
{
  private:
    int countPainters(int arr[], int n, int time){
        int painters = 1;
        int t = 0;
        
        for(int i = 0; i<n; i++) {
            if(arr[i] + t <= time) t += arr[i];
            else {
                painters++;
                t = arr[i];
            }
        }
        
        return painters;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long low = INT_MIN, high = 0;
        for(int i = 0; i<n; i++) {
            if(arr[i] > low) low = arr[i];
            high += arr[i];
        }
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(countPainters(arr, n, mid) > k) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}