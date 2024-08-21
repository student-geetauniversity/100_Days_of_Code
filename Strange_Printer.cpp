#include <bits/stdc++.h>
using namespace std;

int strangePrinter(const string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1];
            }
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    cout << "Enter the string: ";
    string s;
    getline(cin, s);
    cout << "Minimum number of turns required: " << strangePrinter(s) << endl;
    return 0;
}
