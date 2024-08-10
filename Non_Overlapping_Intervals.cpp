#include<bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
   
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int end = intervals[0][1];
    int count = 0;
    
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < end) {
            ++count; 
        } else {
            end = intervals[i][1]; 
        }
    }
    
    return count;
}

int main() {
    int n;
    
    cout << " Enter number of intervals : " ;
    cin >> n; 
    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter elements of Intervals : ";
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    cout << "Minimum number of intervals you need to remove are : ";
    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}
