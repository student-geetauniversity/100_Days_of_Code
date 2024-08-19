#include<bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    if (n == 1) 
    return 0;

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                dp[i] = min(dp[i], dp[j] + i / j);
                if (j != i / j) {
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of characters to reach: ";
    cin >> n;
    cout << "Minimum steps required: " << minSteps(n) << endl;
    return 0;
}
