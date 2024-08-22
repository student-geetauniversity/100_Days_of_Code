#include <bits/stdc++.h>
using namespace std;

int findComplement(int num) {
    int mask = 1;
    while (mask < num) {
        mask = (mask << 1) | 1;
    }
    return ~num & mask;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The complement of " << num << " is " << findComplement(num) << endl;
    return 0;
}
