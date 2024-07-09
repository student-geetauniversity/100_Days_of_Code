#include <bits/stdc++.h>
using namespace std;

double average_Waiting_Time(vector<vector<int>>& customers) {
    const int n = customers.size();
    double time = 0, sum = 0;
    for(auto& t : customers) {
        time = ((t[0] > time) ? t[0] : time) + t[1];
        sum += time - t[0];
    }
    return sum / n;
}

int main() {
    int num_customers;
    cout << "Enter number of customers: ";
    cin >> num_customers;

    vector<vector<int>> customers(num_customers, vector<int>(2));
    cout << "Enter arrival time and service time for each customer:" << endl;
    for (int i = 0; i < num_customers; ++i) {
        cout << "Customer " << i + 1 << ": ";
        cin >> customers[i][0] >> customers[i][1];
    }

    cout << "Average waiting time: " << average_Waiting_Time(customers) << endl;
    
    return 0;
}
