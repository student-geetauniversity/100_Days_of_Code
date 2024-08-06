#include <bits/stdc++.h>
using namespace std;

int minimumPushes(const string& word) {
    vector<int> letterFreq(26, 0);
    for (char c : word) {
        letterFreq[c - 'a']++;
    }
    
    sort(letterFreq.rbegin(), letterFreq.rend());
    
    int totalPresses = 0;
    for (int i = 0; i < 26; i++) {
        if (letterFreq[i] == 0) break;
        totalPresses += (i / 8 + 1) * letterFreq[i];
    }
    
    return totalPresses;
}

int main() {
    string word;
    cout << "Enter the String : ";
    cin >> word;  
    
    cout << "Minimum Number of Pushes are : " << minimumPushes(word) << endl;  
    return 0;
}
