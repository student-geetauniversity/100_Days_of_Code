#include <bits/stdc++.h>
using namespace std;

string another(unsigned int num, string ans) {
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    if (num / 16 == 0) 
        return arr[num % 16] + ans;

    return another(num / 16, arr[num % 16] + ans);
}

string toHex(int num) {
    unsigned int n = num;
    string ans = another(n, "");
    return ans;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    string hexValue = toHex(num);
    cout << "Hexadecimal: " << hexValue << endl;

    return 0;
}
