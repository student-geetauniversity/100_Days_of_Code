#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<int> stk;
    int currentNumber = 0;
    int sign = 1; 
    int currentResult = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        } else if (c == '+') {
            currentResult += sign * currentNumber;
            currentNumber = 0;
            sign = 1;
        } else if (c == '-') {
            currentResult += sign * currentNumber;
            currentNumber = 0;
            sign = -1;
        } else if (c == '(') {
            stk.push(currentResult);
            stk.push(sign);
            currentResult = 0;
            sign = 1;
        } else if (c == ')') {
            currentResult += sign * currentNumber;
            currentNumber = 0;
            currentResult *= stk.top();
            stk.pop();
            currentResult += stk.top();
            stk.pop();
        }
    }
    
    currentResult += sign * currentNumber;
    
    return currentResult;
}

int main() {
    string s;
    cout << "Enter a mathematical expression: ";
    getline(cin, s);
    
    int result = calculate(s);
    cout << "The result is: " << result << endl;
    
    return 0;
}
