#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
    int height, width, depth;

    Box(int h, int w, int d) : height(h), width(w), depth(d) {}

    int baseArea() const {
        return width * depth;
    }
};

bool compare(const Box &a, const Box &b) {
    return a.baseArea() > b.baseArea();
}

vector<Box> generateRotations(vector<Box> &boxes) {
    vector<Box> rotations;
    for (const Box &box : boxes) {
        int h = box.height, w = box.width, d = box.depth;
        rotations.emplace_back(h, max(w, d), min(w, d)); // Height as it is
        rotations.emplace_back(w, max(h, d), min(h, d)); // Width as height
        rotations.emplace_back(d, max(h, w), min(h, w)); // Depth as height
    }
    return rotations;
}

int maxStackHeight(vector<Box> &boxes) {
    vector<Box> rotations = generateRotations(boxes);

    sort(rotations.begin(), rotations.end(), compare);

    int n = rotations.size();
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        dp[i] = rotations[i].height;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (rotations[i].width < rotations[j].width && rotations[i].depth < rotations[j].depth) {
                dp[i] = max(dp[i], dp[j] + rotations[i].height);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter the number of boxes: ";
    cin >> n;

    vector<Box> boxes;
    cout << "Enter the dimensions of each box (height, width, depth):" << endl;
    for (int i = 0; i < n; i++) {
        int h, w, d;
        cin >> h >> w >> d;
        boxes.emplace_back(h, w, d);
    }

    int result = maxStackHeight(boxes);
    cout << "The maximum height of the stack is: " << result << endl;

    return 0;
}
