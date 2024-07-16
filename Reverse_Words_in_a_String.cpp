#include <bits/stdc++.h>
using namespace std;

class Solution { 
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        string word = "";
        
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                word += s[i];
            } else {
                if(word.size() > 0) {
                    st.push(word);
                }
                word = "";
            }
        }
        
        if(word.size() > 0) {
            st.push(word);
        }
        
        s.clear();
        while(!st.empty()) {
            s += st.top();
            st.pop();
            s += " ";
        }
        
        if(!s.empty()) {
            s.pop_back(); 
        }
        
        return s;
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string result = solution.reverseWords(input);
    cout << "Reversed words: " << result << endl;

    return 0;
}
