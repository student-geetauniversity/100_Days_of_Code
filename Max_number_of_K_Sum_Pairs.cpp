#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int count = 0;

    for (int num : nums) {
        int complement = k - num;

        if (mp[complement] > 0) {
            count++;
            mp[complement]--; 
        } else {
            mp[num]++;
        }
    }

    return count;
}

int main() {
    int n, k;
    cout << "Enter size of an Array : " ;
    cin >> n ;
    vector<int> nums(n);

cout << "Enter elements of an array : " ;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
     cout << "Enter the value of K : " ;
     cin >> k ;
     
     cout << "maximum number of operations are " ;
    cout << maxOperations(nums, k) << endl;

    return 0;
}
