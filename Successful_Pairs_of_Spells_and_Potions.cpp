#include <bits/stdc++.h>
using namespace std;

vector<int> successfulPairs(const vector<int>& spells, const vector<int>& potions, long long success) {
    vector<int> sorted_potions = potions; 
    sort(sorted_potions.begin(), sorted_potions.end());
    
    vector<int> result;
    
    for (int spell : spells) {
        long long minPotion = (success + spell - 1) / spell;
        int count = sorted_potions.end() - lower_bound(sorted_potions.begin(), sorted_potions.end(), minPotion);
        result.push_back(count);
    }
    
    return result;
}

int main() {
    int n, m;
    long long success;
    
    cout << "Enter the number of spells: ";
    cin >> n;
    vector<int> spells(n);
    cout << "Enter the spell values: ";
    for (int i = 0; i < n; ++i) {
        cin >> spells[i];
    }
    
    cout << "Enter the number of potions: ";
    cin >> m;
    vector<int> potions(m);
    cout << "Enter the potion values: ";
    for (int i = 0; i < m; ++i) {
        cin >> potions[i];
    }
    
    cout << "Enter the success threshold: ";
    cin >> success;
    
    vector<int> result = successfulPairs(spells, potions, success);
    
    cout << "Number of successful pairs for each spell: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}
