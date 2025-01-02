#include <iostream>
#include <vector>
using namespace std;

long long count_right_triangles(int n, vector<pair<int, int>>& points) {
    int count_y0 = 0;  // Number of points with y = 0
    int count_y1 = 0;  // Number of points with y = 1
    
    for (auto& point : points) {
        if (point.second == 0) {
            count_y0++;
        } else if (point.second == 1) {
            count_y1++;
        }
    }
    
    long long triangles = 0;
    
    // Calculate the number of right triangles
    if (count_y0 >= 2 && count_y1 >= 1) {
        triangles += static_cast<long long>(count_y0) * (count_y0 - 1) / 2 * count_y1;
    }
    
    if (count_y1 >= 2 && count_y0 >= 1) {
        triangles += static_cast<long long>(count_y1) * (count_y1 - 1) / 2 * count_y0;
    }
    
    return triangles;
}

int main() {
    int t;
    cin >> t;
    vector<long long> results(t);
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<pair<int, int>> points(n);
        
        for (int j = 0; j < n; ++j) {
            cin >> points[j].first >> points[j].second;
        }
        
        results[i] = count_right_triangles(n, points);
    }
    
    for (const auto& result : results) {
        cout << result << endl;
    }
    
    return 0;
}
