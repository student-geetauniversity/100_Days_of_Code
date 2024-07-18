#include <bits/stdc++.h>
using namespace std;

vector<int> nodesBetweenCriticalPoints(const vector<int>& arr) {
    vector<int> criticalPoints;

    int n = arr.size();
    int position = 0;
    
    for (int i = 1; i < n - 1; i++) {
        if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ||
            (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
            criticalPoints.push_back(i);
        }
    }
    
    if (criticalPoints.size() < 2) {
        return {-1, -1};
    }
    
    int minDistance = INT_MAX;
    int maxDistance = criticalPoints.back() - criticalPoints.front();
    
    for (int i = 1; i < criticalPoints.size(); i++) {
        minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
    }
    
    return {minDistance, maxDistance};
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> result = nodesBetweenCriticalPoints(arr);
    
    if (result[0] == -1 && result[1] == -1) {
        cout << "There are no Critical points\n";
    } else {
        cout << "Minimum distance b/w critical points: " << result[0] << endl;
        cout << "Maximum distance b/w critical points: " << result[1] << endl;
    }
    
    return 0;
}
