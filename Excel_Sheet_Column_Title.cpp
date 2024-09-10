#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {
    string ans = "";
    while (columnNumber > 0) {
        columnNumber--;  
        ans = char(columnNumber % 26 + 'A') + ans;
        columnNumber /= 26;
    }
    return ans;
}

int main() {
    int columnNumber;
    cout << "Enter the column number: ";
    cin >> columnNumber;

    cout << "The column title is: " << convertToTitle(columnNumber) << endl;

    return 0;
}
