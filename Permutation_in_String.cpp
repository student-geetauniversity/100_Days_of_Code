#include <bits/stdc++.h>
using namespace std;

bool compareFrequency(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if (n > m) return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    for (int i = 0; i < n; i++) {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (compareFrequency(freq1, freq2)) {
        return true;
    }

    for (int i = n; i < m; i++) {
        freq2[s2[i] - 'a']++;
        freq2[s2[i - n] - 'a']--;

        if (compareFrequency(freq1, freq2)) {
            return true;
        }
    }
    return false;
}

int main() {
     string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }


    return 0;
}
