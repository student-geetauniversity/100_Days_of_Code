#include<bits/stdc++.h>
using namespace std;

int minSubarray(vector<int>& nums, int p) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum = (totalSum + num) % p;
    }
    if (totalSum == 0) return 0;

    unordered_map<int, int> prefixMap;
    prefixMap[0] = -1; 
    int currentSum = 0;
    int minLength = nums.size();
    
    for (int i = 0; i < nums.size(); i++) {
        currentSum = (currentSum + nums[i]) % p;
        int target = (currentSum - totalSum + p) % p;
        
        if (prefixMap.find(target) != prefixMap.end()) {
            minLength = min(minLength, i - prefixMap[target]);
        }
        prefixMap[currentSum] = i;
    }
    
    return minLength == nums.size() ? -1 : minLength;
}

int main() {
    int n, p;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the value of p: ";
    cin >> p;

    int result = minSubarray(nums, p);
    cout << "The minimum length of subarray is: " << result << endl;

    return 0;
}
