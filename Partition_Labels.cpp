#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
    unordered_map<char, int> lastIndex;
    for (int i = 0; i < s.size(); ++i) {
        lastIndex[s[i]] = i;
    }

    vector<int> result;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        end = max(end, lastIndex[s[i]]);
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<int> result = partitionLabels(s);

    cout << "Partition sizes: ";
    for (int size : result) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
