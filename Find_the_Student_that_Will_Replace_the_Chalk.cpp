#include <bits/stdc++.h>
using namespace std;

int chalkReplacer(const vector<int>& chalk, long long k) {
    long long Sum = accumulate(chalk.begin(), chalk.end(), 0LL);
    k %= Sum;

    for (int i = 0; i < chalk.size(); ++i) {
        if (chalk[i] > k) {
            return i;
        }
        k -= chalk[i];
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the chalk array: ";
    cin >> n;
    
    vector<int> chalk(n);
    cout << "Enter the elements of the chalk array: ";
    for (int i = 0; i < n; ++i) {
        cin >> chalk[i];
    }

    long long k;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = chalkReplacer(chalk, k);
    cout << "The index of the student who will get the last piece of chalk is: " << result << endl;

    return 0;
}
