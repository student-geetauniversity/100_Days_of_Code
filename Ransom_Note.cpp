#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> ransomCount;
    unordered_map<char, int> magazineCount;

    for (char c : ransomNote) {
        ransomCount[c]++;
    }

    for (char c : magazine) {
        magazineCount[c]++;
    }

    for (const auto& entry : ransomCount) {
        char c = entry.first;
        int needed = entry.second;
        if (magazineCount[c] < needed) {
            return false;
        }
    }

    return true;
}

int main() {
    string ransomNote, magazine;
    
    cout << "Enter the ransom note: ";
    getline(cin, ransomNote);
    
    cout << "Enter the magazine: ";
    getline(cin, magazine);

    if (canConstruct(ransomNote, magazine)) {
        cout << "The ransom note can be constructed from the magazine." << endl;
    } else {
        cout << "The ransom note cannot be constructed from the magazine." << endl;
    }

    return 0;
}
