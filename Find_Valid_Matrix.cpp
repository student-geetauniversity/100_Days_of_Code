#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int Number_rows = rowSum.size();
    int Number_columns = colSum.size();
    vector<vector<int>> result(Number_rows, vector<int>(Number_columns, 0));

    int i = 0, j = 0;

    while (i < Number_rows && j < Number_columns) {
        int val = min(rowSum[i], colSum[j]);
        result[i][j] = val;
        colSum[j] -= val;
        rowSum[i] -= val;

        if (colSum[j] == 0) {
            j++;
        }
        if (rowSum[i] == 0) {
            i++;
        }
    }
    return result;
}

int main() {
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<int> rowSum(rows), colSum(cols);

    cout << "Enter row sums:" << endl;
    for (int i = 0; i < rows; ++i) {
        cin >> rowSum[i];
    }

    cout << "Enter column sums:" << endl;
    for (int j = 0; j < cols; ++j) {
        cin >> colSum[j];
    }

    vector<vector<int>> result = restoreMatrix(rowSum, colSum);

    cout << "Resulting matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
