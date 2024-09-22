#include <bits/stdc++.h>
using namespace std;

int number(long x, long y, long n) {
    int space = 0; 
    while (x <= n) {
        space += min(n + 1, y) - x;
        x *= 10;
        y *= 10;
    }
    return space;
}

int findKthNumber(long n, int k) {
    long num = 1;
    for (int i = 1; i < k;) {
        int req = number(num, num + 1, n);
        if (i + req <= k) {
            i += req;
            num++;
        } else {
            i++;
            num *= 10;
        }
    }
    return num;
}

int main() {
    long n;
    int k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << "The " << k << "-th smallest number in lexicographical order from 1 to " << n << " is: " << findKthNumber(n, k) << endl;

    return 0;
}
