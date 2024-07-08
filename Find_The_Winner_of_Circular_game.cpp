#include<bits/stdc++.h>
using namespace std;
int findTheWinner(int n, int k) {
       if (n==1) 
       return 1;
       return (findTheWinner(n-1, k)+(k-1))% n+1;
    }
int main(){
      int n, k;
      cin >> n>> k;
      cout << "The winner is friend " << findTheWinner(n,k) << endl;
        return 0;
}
