#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> minimum_row;
        for (int i = 0; i < n; i++) {
            int min_row = INT_MAX;
            for (int j = 0; j < m; j++) {
                min_row = min(min_row, matrix[i][j]);
            }
            minimum_row.push_back(min_row);
        }

        vector<int> maximum_col;
        for (int i = 0; i < m; i++) {
            int max_col = INT_MIN;
            for (int j = 0; j < n; j++) {
                max_col = max(max_col, matrix[j][i]);
            }
            maximum_col.push_back(max_col);
        }

        vector<int> luckyNumbers;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == minimum_row[i] && matrix[i][j] == maximum_col[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    Solution solution;
    vector<int> result = solution.luckyNumbers(matrix);

    cout << "Lucky Numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
