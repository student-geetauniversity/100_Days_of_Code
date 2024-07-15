#include <bits/stdc++.h>
using namespace std;

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);
vector<int> maxNumber(vector<int> nums, int k);
vector<int> maxNumber(vector<int> nums1, vector<int> nums2);

int main() {
    int n1, n2, k;
    cout << "Enter the size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter the elements of first array: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter the size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter the elements of second array: ";
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> result = maxNumber(nums1, nums2, k);

    cout << "The maximum number formed is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> integer;
    int k1;
    for (k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1)
        integer = max(integer, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k - k1)));
    return integer;
}

vector<int> maxNumber(vector<int> nums, int k) {
    int drop = nums.size() - k;
    vector<int> exit;
    for (int num : nums) {
        while (drop && !exit.empty() && exit.back() < num) {
            exit.pop_back();
            drop--;
        }
        exit.push_back(num);
    }
    exit.resize(k);
    return exit;
}

vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
    vector<int> exit;
    while (!nums1.empty() || !nums2.empty()) {
        vector<int>& now = (nums1 > nums2 ? nums1 : nums2);
        exit.push_back(now[0]);
        now.erase(now.begin());
    }
    return exit;
}
