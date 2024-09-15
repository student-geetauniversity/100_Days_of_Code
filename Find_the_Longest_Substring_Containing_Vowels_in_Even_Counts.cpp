#include <bits/stdc++.h>
using namespace std;

int findTheLongestSubstring(const string &s) {
    map<int, int> mp;
    mp[0] = -1;
    int count = 0, ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            count ^= (1 << (s[i] - 'a'));
        }
        if (mp.count(count)) {
            ans = max(ans, i - mp[count]);
        } else {
            mp[count] = i;
        }
    }
    return ans;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    int result = findTheLongestSubstring(s);
    cout << "The length of the longest substring with an even number of vowels is: " << result << endl;
    
    return 0;
}
