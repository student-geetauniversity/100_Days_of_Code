#include <bits/stdc++.h>
using namespace std;

vector<int> sums;
vector<vector<int>> memo;

int calculateMaxStones(const vector<int>& piles, int index, int M) {
    int n = piles.size();
    if (index >= n) {
        return 0;
    }
    if (2 * M >= n - index) {
        return sums[index];
    }
    if (memo[index][M] != -1) {
        return memo[index][M];
    }
    int minValue = INT_MAX;
    for (int x = 1; x <= 2 * M; ++x) {
        minValue = min(minValue, calculateMaxStones(piles, index + x, max(M, x)));
    }
    memo[index][M] = sums[index] - minValue;
    return memo[index][M];
}

int stoneGameII(const vector<int>& piles) {
    int n = piles.size();
    if (n == 0) {
        return 0;
    }
    sums.resize(n);
    sums[n - 1] = piles[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        sums[i] = sums[i + 1] + piles[i];
    }
    memo.assign(n, vector<int>(n + 1, -1));
    return calculateMaxStones(piles, 0, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "Enter the number of piles: ";
    int n;
    cin >> n;
    
    vector<int> piles(n);
    cout << "Enter the piles: ";
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }
    
    int result = stoneGameII(piles);
    cout << "Maximum number of stones the first player can collect: " << result << '\n';
    
    return 0;
}
