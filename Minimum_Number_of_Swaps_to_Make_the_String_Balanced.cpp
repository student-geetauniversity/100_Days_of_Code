#include<bits/stdc++.h>
using namespace std;

int minSwaps(string s) {
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ']' && st.empty()) {
            continue;
        }
        else if(s[i] == ']' && st.top() == '[') {
            st.pop();
        }
        else {
            st.push('[');
        }
    }
    
    return (st.size() + 1) / 2;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    int result = minSwaps(s);
    
    cout << "Minimum number of swaps: " << result << endl;
    
    return 0;
}
