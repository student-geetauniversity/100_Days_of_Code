#include <bits/stdc++.h>
using namespace std;

int numTilings(int n) {
    const int MOD = 1e9 + 7;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    int result = numTilings(n);
    cout << "The number of ways to tile a 2 x " << n << " board is: " << result << endl;

    return 0;
}
