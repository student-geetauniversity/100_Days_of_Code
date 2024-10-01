#include <bits/stdc++.h>
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    vector<int> frequency(k, 0);
    
    for (int n : arr) {
        int remainder = ((n % k) + k) % k;
        frequency[remainder]++;
    }
   
    if (frequency[0] % 2 != 0){
        return false; 
    }

    for (int i = 1; i <= k / 2; i++) {
        if (frequency[i] != frequency[k - i]){
             return false; 
        }
    }
    
    return true;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (canArrange(arr, k)) {
        cout << "Yes, the array can be arranged." << endl;
    } else {
        cout << "No, the array cannot be arranged." << endl;
    }

    return 0;
}


