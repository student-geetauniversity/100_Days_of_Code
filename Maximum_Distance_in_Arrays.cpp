#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int n = arrays.size();
    if (n == 0)
        return 0;
        
    int minVal = arrays[0][0];
    int maxVal = arrays[0].back();
    int maxDistance = 0;
    
    for (int i = 1; i < n; ++i) {
        int localMin = arrays[i][0];
        int localMax = arrays[i].back();
        maxDistance = max(maxDistance, abs(localMax - minVal));
        maxDistance = max(maxDistance, abs(maxVal - localMin));
        minVal = min(minVal, localMin);
        maxVal = max(maxVal, localMax);
    }

    return maxDistance;
}

int main() {
    int n;
    cout << "Enter the number of arrays: ";
    cin >> n;
    
    vector<vector<int>> arrays(n);
    
    for (int i = 0; i < n; ++i) {
        int k;
        cout << "Enter the size of array " << i + 1 << ": ";
        cin >> k;
        
        arrays[i].resize(k);
        cout << "Enter " << k << " elements for array " << i + 1 << ": ";
        for (int j = 0; j < k; ++j) {
            cin >> arrays[i][j];
        }
    }

    cout << "Maximum distance: " << maxDistance(arrays) << '\n';

    return 0;
}
