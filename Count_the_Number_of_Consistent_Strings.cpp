#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed,vector<string>& words) {
        int count = words.size();
 unordered_set<char> set(allowed.begin(), allowed.end());

        for (const string& word : words) {
            for (char ch : word) {
                if (set.find(ch) == set.end()) {
                    count--;  
                    break;
                }
            }
        }

        return count;
    }

int main() {
    string allowed;
    int numWords;
    
    cout << "Enter allowed characters: ";
    cin >> allowed;
    
    cout << "Enter number of words: ";
    cin >> numWords;
    
    vector<string> words(numWords);
    cout << "Enter the words:" << endl;
    for (int i = 0; i < numWords; ++i) {
        cin >> words[i];
    }

    int result = countConsistentStrings(allowed, words);
    
    cout << "Number of consistent strings: " << result << endl;

    return 0;
}
