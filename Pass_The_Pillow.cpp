#include<bits/stdc++.h>
using namespace std;
int passThePillow(int n, int time) {
        int N = 2*n-2 ;
        int X= time % N;
        int result = (X<n)?X:N-X;
        return 1+result;
        
    }
int main(){
    int n,time;
    cin >> n >> time;
    cout << passThePillow(n,time) << endl;
    return 0;
}
