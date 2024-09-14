#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
      
        int maximum_value = nums[0];
        int maximum_length = 1;
        int current_length = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > maximum_value) {
                maximum_value = nums[i];
                maximum_length = 1;
                current_length = 1;
            } else if (nums[i] == maximum_value) {
                current_length++;
    maximum_length = max(maximum_length, current_length);
            } else {
                current_length = 0;
            }
        }
        
     return maximum_length;
    }

int main() {
    int n;
   cout << "Enter the number of elements: ";
   cin >> n;

   vector<int> nums(n);
   cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = longestSubarray(nums);
    cout << "The length of the longest subarray with the maximum value is: " << result << endl;

    return 0;
}
