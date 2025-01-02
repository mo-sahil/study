#include <iostream>
#include <vector>
#include <algorithm>

void maxHeapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(std::vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void filterAndPrintMaxHeap(std::vector<int>& arr, int n, int a, int b) {
    // Filtering elements outside the range [a, b]
    arr.erase(std::remove_if(arr.begin(), arr.end(),
                             [a, b](int x) { return x < a || x > b; }),
              arr.end());

    // Building Max Heap
    buildMaxHeap(arr, arr.size());

    // Printing the result
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int a, b;
    std::cin >> a >> b;

    filterAndPrintMaxHeap(arr, N, a, b);

    return 0;
}
