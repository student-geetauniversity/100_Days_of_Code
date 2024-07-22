#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); i++) {
            people.push_back({heights[i], names[i]});
        }
        sort(people.rbegin(), people.rend());
        vector<string> result;
        for (auto p : people) {
            result.push_back(p.second);
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    
    vector<string> names(n);
    vector<int> heights(n);

    cout << "Enter names :\n";
    for (int i = 0; i < n; ++i) {
        cin >> names[i] ;
    }

 cout << "Enter heights:\n";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    Solution sol;
    vector<string> sortedNames = sol.sortPeople(names, heights);

    cout << "Sorted names based on heights:\n";
    for (const auto &name : sortedNames) {
        cout << name << endl;
    }

    return 0;
}
