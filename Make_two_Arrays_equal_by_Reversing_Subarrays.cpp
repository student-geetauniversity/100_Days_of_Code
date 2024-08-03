#include<bits/stdc++.h>
using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        int n = target.size();
        for(int i=0;i<n;i++){
            if(target[i]!=arr[i]){
                return false;
            }
        }
        return true;
    }
int main(){
    int n ;
    cout << "Enter the size of an array : ";
    cin >> n ;
    
    vector<int> target(n);
    cout << "Enter the Target array : ";
    for(int i=0;i<n;i++){
        cin >> target[i];
    }
    
    vector<int> arr(n);
    cout << "Enter the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    if(canBeEqual(target,arr)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}
