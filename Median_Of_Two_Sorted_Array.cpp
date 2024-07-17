#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
    int n = v1.size() + v2.size();
    vector<int> merged_array(n);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), merged_array.begin());

    if (n % 2 == 0) {
        return (merged_array[n/2 - 1] + merged_array[n/2]) / 2.0;
    } else {
        return merged_array[n/2];
    }
}

int main() {
    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    cout << "Enter elements of first array (sorted): ";
    vector<int> v1(m);
    for (int i = 0; i < m; ++i) {
        cin >> v1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;
    cout << "Enter elements of second array (sorted): ";
    vector<int> v2(n);
    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
    }

    double median = findMedianSortedArrays(v1, v2);
    cout << "Median of the merged sorted arrays: " << median << endl;

    return 0;
}
