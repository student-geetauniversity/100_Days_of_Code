#include<bits/stdc++.h>
using namespace std;

long long dividePlayers(vector<int>& skill) {
    int n = skill.size();
    sort(skill.begin(), skill.end());
    long long ans = 0, target = skill[0] + skill[n - 1], val1, val2;

    int i = 0, j = n - 1;
    while(i < j) {
        val1 = skill[i++];
        val2 = skill[j--];
        if(val1 + val2 != target) {
            return -1;
        }
        ans += (val1 * val2);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of players: ";
    cin >> n;
    
    vector<int> skill(n);
    
    cout << "Enter the skill levels of the players: ";
    for(int i = 0; i < n; i++) {
        cin >> skill[i];
    }

    long long result = dividePlayers(skill);
    
    if(result == -1) {
        cout << "-1" << endl;
    } else {
        cout << "The answer is: " << result << endl;
    }
    
    return 0;
}
