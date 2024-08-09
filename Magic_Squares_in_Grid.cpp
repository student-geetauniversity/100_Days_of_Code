#include <bits/stdc++.h>
using namespace std;

bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
    vector<int> nums;
    for (int i = row; i < row + 3; ++i) {
        for (int j = col; j < col + 3; ++j) {
            nums.push_back(grid[i][j]);
        }
    }
    
    if (nums.size() != 9) 
     return false;
    
    sort(nums.begin(), nums.end());
    for (int i = 0; i < 9; ++i) {
        if (nums[i] != i + 1)
         return false;
    }
    
    int targetSum = 15; 
    for (int i = row; i < row + 3; ++i) {
        if (grid[i][col] + grid[i][col + 1] + grid[i][col + 2] != targetSum) 
           return false;
    }
    
    for (int j = col; j < col + 3; ++j) {
        if (grid[row][j] + grid[row + 1][j] + grid[row + 2][j] != targetSum) 
           return false;
    }
    
    if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != targetSum) 
    return false;
    if (grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2] != targetSum) 
      return false;
    
    return true;
}

int numMagicSquaresInside(const vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0;
    
    if (n < 3 || m < 3)
      return count;
    
    for (int i = 0; i <= n - 3; ++i) {
        for (int j = 0; j <= m - 3; ++j) {
            if (isMagicSquare(grid, i, j)) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int rows, cols;
    
    cout << "Enter rows : ";
    cin >> rows ;
    
    cout << "Enter Columns : ";
    cin >> cols;
    
    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter Grid Elements : ";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }
    
    cout << "Magic square inside the given grid are : " << numMagicSquaresInside(grid) << endl;
    
    return 0;
}
