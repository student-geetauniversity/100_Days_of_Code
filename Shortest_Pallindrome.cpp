#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s) {
    int n = s.size();
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (s[i] == s[n - j - 1]) {
            i++;
        }
    }
    if (i == n) {
        return s;
    }
    string rem = s.substr(i, n);
    reverse(rem.begin(), rem.end());
    return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string result = shortestPalindrome(s);
    cout << "Shortest Palindrome: " << result << endl;
    return 0;
}
