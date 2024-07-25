#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(26, 0); 
        for (char c : s) {
            count[c - 'a']++;
        }

        for (char c : t) {
            count[c - 'a']--;
           
            if (count[c - 'a'] < 0) {
                return c;
            }
        }

        return ' '; 
    }
};

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    Solution sol;
    char result = sol.findTheDifference(s, t);

    cout << "The extra character in t is: " << result << endl;

    return 0;
}
