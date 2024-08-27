#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;
    
    vector<int> v;
    v.push_back(1);
    ans.push_back(v);
    
    for (int i = 1; i < numRows; i++) {
        vector<int> v1;
        v1.push_back(1);
        for (int j = 1; j < i; j++) {
            v1.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        v1.push_back(1);
        ans.push_back(v1);
    }
    
    return ans;
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    
    vector<vector<int>> result = generate(numRows);
    
    cout << "Generated Pascal's Triangle:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
