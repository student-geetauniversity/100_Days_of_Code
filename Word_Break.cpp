#include <bits/stdc++.h>
using namespace std;

bool wordBreak(const string& s, const vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}

int main() {
    string s;
    int dictSize;
    
    cout << "Enter the string to be segmented: ";
    cin >> s;
    
    cout << "Enter the number of words in the dictionary: ";
    cin >> dictSize;
    
    vector<string> wordDict(dictSize);
    
    cout << "Enter the words in the dictionary:\n";
    for (int i = 0; i < dictSize; ++i) {
        cin >> wordDict[i];
    }
    
    if (wordBreak(s, wordDict)) {
        cout << "The string can be segmented into words from the dictionary.\n";
    } else {
        cout << "The string cannot be segmented into words from the dictionary.\n";
    }
    
    return 0;
}
