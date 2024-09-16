#include <bits/stdc++.h>
using namespace std;

int findSingleNumber(const vector<int>& nums) {
    int ans = 0;
    for(int num : nums) {
        ans = ans ^ num;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter the elements: ";
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = findSingleNumber(nums);
    cout << "The single number is: " << result << endl;
    
    return 0;
}
