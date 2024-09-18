#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), compare);

    if (nums[0] == 0) return "0";

    string ans;
    for (int n : nums) ans += to_string(n);

    return ans;
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

    string result = largestNumber(nums);
    cout << "Largest number formed: " << result << endl;

    return 0;
}
