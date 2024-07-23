# include <bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> frequency;
    for (int i : nums) {
        frequency[i]++;
    }
    sort(nums.begin(), nums.end(), [&](int n1, int n2) {
        if (frequency[n1] != frequency[n2]) {
            return frequency[n1] < frequency[n2];
        } else {
            return n2 < n1;
        }
    });
    return nums;
}

int main() {
    vector<int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> sorted_nums = frequencySort(nums);

    cout << "Sorted array based on frequency:\n";
    for (int num : sorted_nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
