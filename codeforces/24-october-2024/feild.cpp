#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void minimize_disturbance(int t, vector<pair<int, vector<int>>>& test_cases) {
    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].first;
        vector<int>& topics = test_cases[i].second;

        unordered_map<int, int> frequency;

        for (int j = 0; j < n; ++j) {
            frequency[topics[j]]++;
        }

        int max_frequency = 0;
        for (auto &entry : frequency) {
            max_frequency = max(max_frequency, entry.second);
        }

        int min_disturbance = n - max_frequency;

        cout << min_disturbance << endl;
    }
}

int main() {
    int t;
    cin >> t;

    vector<pair<int, vector<int>>> test_cases(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> topics(n);
        for (int j = 0; j < n; ++j) {
            cin >> topics[j];
        }
        test_cases[i] = {n, topics};
    }

    minimize_disturbance(t, test_cases);

    return 0;
}
