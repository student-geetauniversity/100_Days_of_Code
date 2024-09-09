#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    vector<int> current = intervals[0];
    for (const auto& interval : intervals) {
        if (interval[0] <= current[1]) {
            current[1] = max(current[1], interval[1]);
        } else {
            merged.push_back(current);
            current = interval;
        }
    }
    merged.push_back(current);
    return merged;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;
    
    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start end) for each interval:\n";
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    vector<vector<int>> result = mergeIntervals(intervals);
    
    cout << "Merged intervals:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
