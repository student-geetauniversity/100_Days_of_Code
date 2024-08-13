#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (citations[mid] >= n - mid) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return n - l;       
}

int main() {
    int n;
    cout << "Enter the number of citations: ";
    cin >> n;
    vector<int> citations(n);
    
    cout << "Enter the citations: ";
    for (int i = 0; i < n; ++i) {
        cin >> citations[i];
    }
    
    int result = hIndex(citations);
    cout << "The H-index is: " << result << endl;

    return 0;
}
