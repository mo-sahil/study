#include <iostream>
#include <vector>
#include <algorithm>  // For std::max

using namespace std;

// Function to perform Counting Sort
void countingSort(vector<int>& arr) {
    // Find the maximum element in the array
    int maxElem = *max_element(arr.begin(), arr.end());

    // Create a count array to store the frequency of elements
    vector<int> count(maxElem + 1, 0);

    // Count the frequency of each element in the array
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= maxElem; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
