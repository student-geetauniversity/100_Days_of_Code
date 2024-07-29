#include<bits/stdc++.h>
using namespace std;

int numTeams(vector<int>& rating) {
    int n = rating.size();
    int count = 0;

    for (int j = 1; j < n - 1; ++j) {
        int leftSmaller = 0, leftLarger = 0;
        int rightSmaller = 0, rightLarger = 0;

        for (int i = 0; i < j; ++i) {
            if (rating[i] < rating[j]) {
                ++leftSmaller;
            } else if (rating[i] > rating[j]) {
                ++leftLarger;
            }
        }

        for (int k = j + 1; k < n; ++k) {
            if (rating[k] < rating[j]) {
                ++rightSmaller;
            } else if (rating[k] > rating[j]) {
                ++rightLarger;
            }
        }

        count += leftSmaller * rightLarger; // For increasing sequences
        count += leftLarger * rightSmaller; // For decreasing sequences
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of soldiers: ";
    cin >> n;

    if (n < 3) {
        cout << "Number of soldiers must be at least 3 to form a valid team." << endl;
        return 0;
    }

    vector<int> rating(n);
    cout << "Enter the ratings of the soldiers: ";
    for (int i = 0; i < n; ++i) {
        cin >> rating[i];
    }

    int result = numTeams(rating);
    cout << "Number of valid teams: " << result << endl;

    return 0;
}
