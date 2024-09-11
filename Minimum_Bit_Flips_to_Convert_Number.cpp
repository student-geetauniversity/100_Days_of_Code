#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    int xor_value = start ^ goal;
    int res = 0;
    while (xor_value > 0) {
        res += xor_value & 1; 
        xor_value >>= 1;        
    }
    return res;
}

int main() {
    int start, goal;
    
    cout << "Enter the start value: ";
    cin >> start;
    
    cout << "Enter the goal value: ";
    cin >> goal;
    
    int result = minBitFlips(start, goal);
    
    cout << "Minimum number of bit flips needed: " << result << endl;
    
    return 0;
}
