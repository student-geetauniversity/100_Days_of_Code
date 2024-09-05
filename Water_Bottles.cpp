#include <bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int totalBottles = numBottles;

    while (numBottles >= numExchange) {
        totalBottles += numBottles / numExchange;
        numBottles = (numBottles / numExchange) + (numBottles % numExchange);
    }

    return totalBottles;
}

int main() {
    int numBottles, numExchange;

    cout << "Enter the number of bottles: ";
    cin >> numBottles;
    cout << "Enter the number of bottles needed for exchange: ";
    cin >> numExchange;

    int result = numWaterBottles(numBottles, numExchange);

    cout << "Total number of bottles that can be drunk: " << result << endl;

    return 0;
}
