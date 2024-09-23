#include <bits/stdc++.h>
using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    unordered_set<string> dict(dictionary.begin(), dictionary.end());

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;

        for (int j = 0; j < i; ++j) {
            string sub = s.substr(j, i - j);
            if (dict.count(sub)) {
                dp[i] = min(dp[i], dp[j]);
            }
        }
    }

    return dp[n];
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int dictSize;
    cout << "Enter the number of words in the dictionary: ";
    cin >> dictSize;

    vector<string> dictionary(dictSize);
    cout << "Enter the words in the dictionary:\n";
    for (int i = 0; i < dictSize; ++i) {
        cin >> dictionary[i];
    }

    int result = minExtraChar(s, dictionary);
    cout << "Minimum extra characters: " << result << endl;

    return 0;
}
