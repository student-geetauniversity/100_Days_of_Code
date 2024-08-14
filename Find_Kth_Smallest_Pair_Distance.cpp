#include <bits/stdc++.h>
using namespace std;

 int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums[0];
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0, j = 0;
            for (int i = 0; i < nums.size(); i++) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) 
                   j++;
                cnt += j - i - 1;
            }
            if (cnt < k) 
               low = mid + 1;
            else
               high = mid;
        }
        return low;
    } 
    

int main()
{
    int n;
    cout << "Enter Size of array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter elements in array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int k;
    cout << "Enter the value of K : ";
    cin >> k;
    
    int result = smallestDistancePair(arr,k); 
    cout << "Smallest Distance among all pairs are : " << result << endl;
    return 0;
}
