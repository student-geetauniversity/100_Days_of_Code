#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0, count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
        } else {
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    return max(maxCount, count);  
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive 1s: " << result << endl;
    
    return 0;
}
