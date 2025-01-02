#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    if (totalSum % 2 != 0) {
        return false;
    }

    int target = totalSum / 2;
    
    vector<bool> dp(target + 1, false);
    dp[0] = true; 

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target]; 
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    
    if (canPartition(nums)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
