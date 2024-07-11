#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";
        for (char c : s) {
            if (c == '(') {
                st.push(current);
                current = "";
            } else if (c == ')') {
                reverse(current.begin(), current.end());
                if (!st.empty()) {
                    current = st.top() + current;
                    st.pop();
                }
            } else {
                current += c;
            }
        }
        return current;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    string result = solution.reverseParentheses(s);
    cout << "The reversed parentheses string is: " << result << endl;

    return 0;
}
