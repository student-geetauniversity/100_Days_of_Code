#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int ans = 0;
        for (int i = 0; i < month - 1; i++) {
            ans += daysInMonth[i];
        }
        
        ans += day;
        
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (month > 2) {
                ans += 1; 
            }
        }
        
        return ans;
    }
};

int main() {
    string date;
    cout << "Enter date in YYYY-MM-DD format: ";
    cin >> date;
    
    Solution solution;
    int result = solution.dayOfYear(date);
    cout << "Day of the year: " << result << endl;
    
    return 0;
}
