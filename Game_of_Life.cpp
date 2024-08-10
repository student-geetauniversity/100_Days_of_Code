#include <bits/stdc++.h>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    vector<vector<int>> newBoard(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + directions[k][0];
                int y = j + directions[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1) {
                    liveNeighbors++;
                }
            }
            if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                newBoard[i][j] = 0;
            } else if (board[i][j] == 0 && liveNeighbors == 3) {
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = board[i][j];
            }
        }
    }
    
    board = newBoard;
}

int main() {
    int m, n;
    cout << "Enter rows : ";
    cin >> m;
    
    cout << "Enter columns : ";
    cin >> n;
    
    vector<vector<int>> board(m, vector<int>(n));
    cout << "Enter elemets of board : ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    gameOfLife(board);
      cout << "The next State of Board is : " << endl;
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
