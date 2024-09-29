#include <bits/stdc++.h>
using namespace std;

bool canAliceWin(vector<int>& nums) 
{
    int sum1 = 0, sum2 = 0;
    for(auto val : nums)
    {
        if(val < 10) sum1 += val;
        else sum2 += val;
    }
    return sum1 != sum2;
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

    if (canAliceWin(nums)) {
        cout << "Alice can win!" << endl;
    } else {
        cout << "Alice cannot win." << endl;
    }

    return 0;
}
