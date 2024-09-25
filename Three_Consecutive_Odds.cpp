#include <bits/stdc++.h>
using namespace std;

bool threeConsecutiveOdds(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            count++;
            if (count == 3) {
                return true;
            }
        } else {
            count = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (threeConsecutiveOdds(arr, n)) {
        cout << "There are three consecutive odd numbers." << endl;
    } else {
        cout << "There are not three consecutive odd numbers." << endl;
    }

    return 0;
}
