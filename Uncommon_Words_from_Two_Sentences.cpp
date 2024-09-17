#include<bits/stdc++.h>
using namespace std;

void frequency(const string& str, unordered_map<string, int>& um) {
    stringstream s(str);
    string word;
    while (s >> word) {
        um[word]++;
    }
}

vector<string> uncommonFromSentences(const string& s1, const string& s2) {
    unordered_map<string, int> um;
    frequency(s1, um);
    frequency(s2, um);
    vector<string> ans;
    for (const auto& w : um) {
        if (w.second < 2) {
            ans.push_back(w.first);
        }
    }
    return ans;
}

int main() {

    string s1, s2;

    cout << "Enter the first sentence: ";
    getline(cin, s1);
    cout << "Enter the second sentence: ";
    getline(cin, s2);
    
    vector<string> result = uncommonFromSentences(s1, s2);

    cout << "Uncommon words: ";
    for (const auto& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
