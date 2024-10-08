#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
    }
    vector<int> right(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1])
            right[i] = right[i + 1] + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(left[i], right[i]);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of ratings: ";
    cin >> n;

    vector<int> ratings(n);
    cout << "Enter the ratings: ";
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    int result = candy(ratings);
    cout << "Minimum candies required: " << result << endl;

    return 0;
}
