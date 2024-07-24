#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    if (m == 0) 
        return 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i + j] == needle[j]) 
            j++;
        if (j == m)
            return i;
    }
    return -1;       
}

int main() {
    string haystack, needle;
    
    cout << "Enter the haystack string: ";
    cin >> haystack;
    cout << "Enter the needle string: ";
    cin >> needle;
    
    int index = strStr(haystack, needle);
    
    if (index == -1)
        cout << "Needle not found in haystack.\n";
    else
        cout << "Needle found at index: " << index << "\n";
    
    return 0;
}
