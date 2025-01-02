#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int start = -1, end = -1;
    int max_seen = INT_MIN, min_seen = INT_MAX;

    for (int i = 0; i < n; ++i) {
        max_seen = max(max_seen, nums[i]);
        if (nums[i] <  max_seen) {
            end = i;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        min_seen = min(min_seen, nums[i]);
        if (nums[i] > min_seen) {
            start = i;
        }
    }

    return (start == -1) ? 0 : (end - start + 1);
}

int main() {
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << "Length of the smallest unsorted subarray: " << findUnsortedSubarray(nums) << endl;
    return 0;
}