#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (st.empty()){
               return false; 
               }           
                char top = st.top();
                if ((s[i] == ')' && top == '(') || (s[i] == '}' && top == '{') || (s[i] == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s; 
    
    Stack solution;
    bool result = solution.isValid(s);
    
    if (result) {
        cout << "This string is valid." << endl;
    } else {
        cout << "This string is not valid." << endl;
    }

    return 0;
}
