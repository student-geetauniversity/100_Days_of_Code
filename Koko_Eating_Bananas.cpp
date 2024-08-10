#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(const vector<int>& piles, int h) {
    int lo = 1, hi = *max_element(piles.begin(), piles.end());
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;
        }
        if (hours > h) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    
    return lo;
}

int main() {
    int n, h;
    cout << "Enter the number of piles: ";
    cin >> n; 
    
    vector<int> piles(n);
    cout << "Enter the pile sizes: ";
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];  
    }
    
    cout << "Enter the number of hours: ";
    cin >> h;  
    
    int result = minEatingSpeed(piles, h);
    
    cout << "The minimum eating speed is: " << result << endl;
    
    return 0;
}
