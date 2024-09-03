#include <bits/stdc++.h>
using namespace std;

int getLucky(const string& s, int k) {
    string numStr = "";
    for (char ch : s) {
        int value = ch - 'a' + 1;
        numStr += to_string(value);
    }

    int result = 0;
    for (int i = 0; i < k; ++i) {
        result = 0;
        for (char ch : numStr) {
            result += ch - '0';
        }
        numStr = to_string(result);
    }

    return result;
}

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the number(k): ";
    cin >> k;

    if (k < 0) {
        cerr << "The number of transformations must be non-negative." << endl;
        return 1;
    }

    int result = getLucky(s, k);
    cout << "The final result is: " << result << endl;

    return 0;
}
