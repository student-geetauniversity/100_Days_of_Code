#include<bits/stdc++.h>
using namespace std;
bool safe(vector<vector<char>>& grid,int row,int col,int n){
      for(int j=col;j>=0;j--){     // Horizontally
        if(grid[row][j] == 'Q')
        return false;
      }
       for(int i=row,j=col;i>=0,j>=0;i--,j--){   // Diagonally (in Upper side)
        if(grid[i][j] == 'Q')
        return false;
      }
       for(int i=row,j=col;i<n && j>=0;i++,j--){     // Diagonally (in Lower side)
        if(grid[i][j] == 'Q')
        return false;
      }
      return true;
}
void solve(vector<vector<char>>& grid,int col,int n){
      if(col == n){          // Base case
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               cout << grid[i][j] << " ";
            } cout << endl;
        } cout << endl;
        return ;
      }
    for(int row=0;row<n;row++){        // Recurence relation
        if(grid[row][col] == '.'){
           if(safe(grid,row,col,n)){
                grid[row][col] = 'Q';
                solve(grid,col+1,n);     // Go and Try For next columns
                grid[row][col] = '.';    // Back Track Condition
           }
        }
      }
}
int main(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char> (n,'.'));
    solve(grid,0,n);
    return 0;
}
