#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0; 
        int mid = 0;   
        int high = nums.size() - 1; 
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (0, 1, 2 only): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution solution;
    solution.sortColors(nums);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
