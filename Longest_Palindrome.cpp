#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(const string& s) {
    unordered_map<char, int> freqMap;
    for (char c : s) {
        freqMap[c]++;
    }
    
    int length = 0;
    bool hasOdd = false;
    
    for (const auto& entry : freqMap) {
        int count = entry.second;
        if (count % 2 == 0) {
            length += count;
        } else {
            length += count - 1;
            hasOdd = true;
        }
    }
    
    if (hasOdd) {
        length += 1;
    }
    
    return length;
}

int main() {
    cout << "Enter a string: ";
    string s;
    cin >> s;
    
    int result = longestPalindrome(s);
    cout << "Length of the longest palindrome that can be built: " << result << endl;
    
    return 0;
}
