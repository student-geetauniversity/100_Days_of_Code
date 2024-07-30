#include <bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    int n = s.size();
    int i = 0, j = 0;
    while (j < n) {
        if (s[j] == '*') {
            i--;
        } else {
            s[i++] = s[j];
        }
        j++;
    }
    return s.substr(0, i);
}

int main() {
    cout << "Enter a string with '*' characters: ";
    string input;
    getline(cin, input);
    
    string result = removeStars(input);
    
    cout << "Processed string: " << result << endl;
    
    return 0;
}
