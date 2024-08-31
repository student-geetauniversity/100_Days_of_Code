#include <bits/stdc++.h> 
using namespace std;

int titleToNumber(const string& columnTitle) {
    int ans = 0;
    for (char c : columnTitle) {
        ans = ans * 26 + (c - 'A') + 1;
    }
    return ans;
}

int main() {
    string columnTitle;
    
    cout << "Enter the column title: ";
    cin >> columnTitle;
    
    int result = titleToNumber(columnTitle);
    
    cout << "The column number is: " << result << endl;
    
    return 0;
}
