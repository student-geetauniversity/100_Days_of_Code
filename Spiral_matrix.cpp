#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int matrix[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
  int left =0 , right = m-1;
   int top =0 , bottom = n-1;
    while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
       cout << matrix[top][i] ;
       cout<<" , ";
    } 
    top++;
     if(top>bottom)
     break;
    for(int j=top;j<=bottom;j++){
       cout << matrix[j][right];
        cout<<" , ";
    } 
      right--;
   if(left>right)
     break;
    for(int i=right;i>=left;i--){
       cout << matrix[bottom][i];
        cout<<" , ";
    }  
      bottom--;
    if(top>bottom)
     break;
    for(int j=bottom;j>=top;j--){
       cout << matrix[j][left];
        cout<<" , ";
    } 
      left++;
    }
    return 0;
}
