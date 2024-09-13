#include <bits/stdc++.h>
using namespace std;

vector<int> xorQueries(const vector<int>& arr, const vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int> prefix(n);
    vector<int> ans(queries.size());

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] ^ arr[i];
    }

    for (int i = 0; i < queries.size(); i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        if (left == 0) {
            ans[i] = prefix[right];
        } else {
            ans[i] = prefix[right] ^ prefix[left - 1];
        }
    }

    return ans;
}

int main() {
    int n, q;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << "Enter the number of queries: ";
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    
    cout << "Enter the queries (each query with two integers): " << endl;
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }
    
    vector<int> results = xorQueries(arr, queries);
    
    cout << "Results of the XOR queries:" << endl;
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
