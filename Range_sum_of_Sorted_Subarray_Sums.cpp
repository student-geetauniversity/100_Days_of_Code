#include <bits/stdc++.h>
using namespace std;

int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> subarraySums;
    for (int start = 0; start < n; ++start) {
        int sum = 0;
        for (int end = start; end < n; ++end) {
            sum += nums[end];
            subarraySums.push_back(sum);
        }
    }
    
    sort(subarraySums.begin(), subarraySums.end());
    
    long long totalSum = 0;
    for (int i = left - 1; i < right; ++i) {
        totalSum += subarraySums[i];
    }

    const int MOD = 1000000007;
    return totalSum % MOD;
}

int main() {
    int n, left, right;
    cout << "Enter size of an array : ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter element in an array : ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    cout << "Enter the left : ";
    cin >> left;
    
    cout << "Enter the Right : ";
    cin >> right;
    
    int result = rangeSum(nums, n, left, right);
    cout << "Sum of Numbers are : " << result << endl;
    
    return 0;
}
