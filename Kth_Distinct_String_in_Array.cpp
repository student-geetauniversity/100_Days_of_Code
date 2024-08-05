#include <bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> map;
    for (const auto& str : arr) {
        map[str]++;
    }

    vector<string> strings;
    for (const auto& str : arr) {
        if (map[str] == 1) {
            strings.push_back(str);
        }
    }

    if (k > strings.size()) {
        return "";
    }
    return strings[k - 1];
}

int main() {
    int n, k;
    cout << "Enter the size of String : ";
    cin >> n;
    
    vector<string> arr(n);
    cout << "Enter the elements in String : ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of K : ";
    cin >> k;
    
    string result = kthDistinct(arr, k);
    cout << "Distinct string present in array is : " << result << endl;

    return 0;
}
