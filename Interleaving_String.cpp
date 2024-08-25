#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    int len = s3.size();
    
    if (m + n != len){
      return false;
    }
    
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                       (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    
    return dp[m][n];
}

int main() {
    string s1, s2, s3;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Enter third string: ";
    cin >> s3;
    
    
    if (isInterleave(s1, s2, s3)) {
        cout << "Yes, third string is an interleaving of the first two strings." << endl;
    } else {
        cout << "No, third string is not an interleaving of the first two strings." << endl;
    }
    
    return 0;
}
