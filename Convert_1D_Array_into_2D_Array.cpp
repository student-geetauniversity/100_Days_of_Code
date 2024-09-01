#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> construct2DArray(const vector<int>& original, int m, int n) {
    const int sz = original.size();
    if (sz != m * n) return {};
    
    vector<vector<int>> ans(m);
    for (int i = 0; i < m; i++) {
        ans[i].assign(original.begin() + i * n, original.begin() + (i + 1) * n);
    }
    return ans;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m) and columns (n): ";
    cin >> m >> n;
    
    int size = m * n;
    
    vector<int> original(size);
    cout << "Enter " << size << " elements for the original array: ";
    for (int i = 0; i < size; i++) {
        cin >> original[i];
    }
    
    vector<vector<int>> result = construct2DArray(original, m, n);
    
    if (result.empty()) {
        cout << "The dimensions do not match the number of elements." << endl;
    } else {
        cout << "The 2D array is:" << endl;
        for (const auto& row : result) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
