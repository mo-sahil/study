#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int sum = 0;
    int count = 0;

    for (int num : nums) {
        sum += num;
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }
        prefixSumCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    cout << "Total number of subarrays whose sum is " << k << ": " << subarraySum(nums, k) << endl;
    return 0;
}