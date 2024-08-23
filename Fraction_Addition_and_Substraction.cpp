#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string fractionAddition(string expression) {
    int num = 0, denom = 1;
    int n = expression.size();
    int i = 0;

    while (i < n) {
        int sign = 1;
        if (expression[i] == '-') {
            sign = -1;
            i++;
        } else if (expression[i] == '+') {
            i++;
        }

        int numerator = 0;
        while (i < n && isdigit(expression[i])) {
            numerator = numerator * 10 + (expression[i] - '0');
            i++;
        }
        numerator *= sign;

        if (i < n && expression[i] == '/') {
            i++;
        }

        int denominator = 0;
        while (i < n && isdigit(expression[i])) {
            denominator = denominator * 10 + (expression[i] - '0');
            i++;
        }

        num = num * denominator + numerator * denom;
        denom *= denominator;

        int g = gcd(abs(num), abs(denom));
        num /= g;
        denom /= g;
    }

    return to_string(num) + '/' + to_string(denom);
}

int main() {
    string expression;
    cout << "Enter the fraction expression: ";
    cin >> expression;

    string result = fractionAddition(expression);
    cout << "Result: " << result << endl;

    return 0;
}
