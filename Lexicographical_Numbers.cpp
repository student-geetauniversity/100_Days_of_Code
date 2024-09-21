#include <bits/stdc++.h>
using namespace std;

void dfs(int temp, int n, vector<int> &ans) {
    if (temp > n) {
        return;
    }

    ans.push_back(temp);
    dfs(temp * 10, n, ans);

    if (temp % 10 != 9) {
        dfs(temp + 1, n, ans);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> ans;
    dfs(1, n, ans);

    cout << "Lexical order: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
