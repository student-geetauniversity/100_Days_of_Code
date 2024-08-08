#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
   vector<vector<int>> res;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        int dirIndex = 0;
        int steps = 1; 
        while (res.size() < rows * cols) {
            for (int i = 0; i < steps; i++) {
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    res.push_back({rStart, cStart});
                }
                rStart += directions[dirIndex][0];
                cStart += directions[dirIndex][1];
            }
            
            dirIndex = (dirIndex + 1) % 4;
            
            if (dirIndex % 2 == 0) {
                steps++;
            }
        }
    return res;
}

int main(){
int rows, cols, rStart, cStart;
    cout << "Enter rows : ";
    cin >> rows ;
    
    cout << "Enter columns : " ;
    cin >> cols;
    
    cout << "Enter rStart : ";
    cin >> rStart;
    
    cout << "Enter cStart : ";
    cin >> cStart;
    
    vector<vector<int>> result = spiralMatrixIII(rows, cols, rStart, cStart);
    cout << "Resulting spiral matrix coordinates are :\n";
    for (const auto& pos : result) {
        cout << "[" << pos[0] << ", " << pos[1] << "] ";
    }
    cout << endl;
    
return 0;
}
