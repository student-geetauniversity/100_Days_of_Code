#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> ans(1, 1);
    for (int i = 1; i <= rowIndex; ++i) {
        vector<int> temp(1, 1);
        for (int j = 0; j < ans.size() - 1; ++j) {
            temp.push_back(ans[j] + ans[j + 1]);
        }
        temp.push_back(1);
        ans = temp;
    }
    return ans;
}

int main() {
    int rowIndex;
    cout << "Enter the row index: ";
    cin >> rowIndex;

    vector<int> result = getRow(rowIndex);

    cout << "Row " << rowIndex << " of Pascal's Triangle is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
