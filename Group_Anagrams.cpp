#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (auto &s : strs) {
        string temp = s;
        sort(temp.begin(), temp.end());
        m[temp].push_back(s);
    }
    vector<vector<string>> ans;
    for (auto &it : m) {
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
    // Read input from the user
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    vector<vector<string>> result = groupAnagrams(strs);

    cout << "Grouped anagrams:\n";
    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
