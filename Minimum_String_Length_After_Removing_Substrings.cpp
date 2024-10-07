#include <bits/stdc++.h>
using namespace std;

int minLength(string s) {
    string temp;
    for(auto ch : s) {
        if(!temp.empty() && ch == 'B' && temp.back() == 'A') 
            temp.pop_back();
        else if(!temp.empty() && ch == 'D' && temp.back() == 'C') 
            temp.pop_back();
        else 
            temp += ch;
    }
    return temp.size();
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    int result = minLength(s);
    cout << "The minimum length of the remaining string is: " << result << endl;

    return 0;
}
