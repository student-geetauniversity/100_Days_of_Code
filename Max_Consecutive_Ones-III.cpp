#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, max_len = 0;
        int n =  nums.size();
        while(right < n) {
            if(nums[right] == 1) right++;
            else if(nums[right] == 0 && k > 0) {
                k--;
                right++;
            }
            else {
                max_len = max(max_len, right - left);
                while(nums[left] == 1) left++;
                if(nums[left] == 0) k++;
                left++;
            }
        }
        max_len = max(max_len, right - left);
        return max_len;        
    }
int main(){
    int n;
    cout << "Enter Size of an array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter elements in an array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int k;
    cout << "Enter the valye of K : ";
    cin >> k;
    
    int result = longestOnes(arr,k);
    cout << "The longest Subarray is : " << result << endl;
    return 0;
}
