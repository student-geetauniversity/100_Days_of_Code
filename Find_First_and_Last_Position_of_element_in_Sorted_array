#include<bits/stdc++.h>
using namespace std;
int findFirstPosition(int arr[],int n, int target){
        int lo=0 , hi=n-1;
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid] == target){
                ans = mid;
                hi = mid-1;
            } else if(arr[mid]<target){
                lo = mid+1;
            }else if(arr[mid]>target){
                hi = mid-1;
            }
        }   return ans;
    }

 int findLastPosition(int arr[], int n, int target){
        int lo=0 , hi=n-1;
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid] == target){
                ans = mid;
                lo = mid+1;;
            } else if(arr[mid]<target){
                lo = mid+1;
            }else if(arr[mid]>target){
                hi = mid-1;
            }
        }
        return ans;
    }

int main(){
       int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
                cin >> arr[i];
        }
        int target;
        cin >> target;
        cout << findFirstPosition(arr,n,target) << " , ";
        cout << findLastPosition(arr,n,target) << endl;
        return 0;
}
