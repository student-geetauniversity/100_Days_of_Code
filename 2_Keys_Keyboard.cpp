#include <bits/stdc++.h>
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
    cout << "Enter the value of n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid input. n must be a positive integer." << endl;
        return 1;
    }

    cout << "Minimum number of steps: " << minSteps(n) << endl;

    return 0;
}
