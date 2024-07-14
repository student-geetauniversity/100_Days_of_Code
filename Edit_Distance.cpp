#include <bits/stdc++.h>

using namespace std;

int topDown(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
    if (i >= word1.length())
        return word2.length() - j;
    if (j >= word2.length())
        return word1.length() - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int ans = INT_MAX;
    if (word1[i] == word2[j]) {
        ans = topDown(word1, word2, i + 1, j + 1, dp);
    } else {
        int replaced = 1 + topDown(word1, word2, i + 1, j + 1, dp);
        int deleted = 1 + topDown(word1, word2, i + 1, j, dp);
        int inserted = 1 + topDown(word1, word2, i, j + 1, dp);
        ans = min(replaced, min(deleted, inserted));
    }
    
    dp[i][j] = ans;
    return dp[i][j];
}

int minDistance(string word1, string word2) {
    if (word1.length() == 0)
        return word2.length();
    if (word2.length() == 0)
        return word1.length();
    
    int i = 0, j = 0;
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
    return topDown(word1, word2, i, j, dp);
}

int main() {
    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    cout << "Enter the second word: ";
    cin >> word2;
    cout << "The minimum edit distance is: " << minDistance(word1, word2) << endl;
    return 0;
}
