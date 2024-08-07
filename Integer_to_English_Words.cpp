#include<bits/stdc++.h>
using namespace std;

string numberToWordsHelper(int n) {
    string one[19] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                      "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
                      "Eighteen", "Nineteen"};
    string ten[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    if (n >= 1000000000) 
    return numberToWordsHelper(n / 1000000000) + " Billion" + numberToWordsHelper(n % 1000000000);
    if (n >= 1000000)
    return numberToWordsHelper(n / 1000000) + " Million" + numberToWordsHelper(n % 1000000);
    if (n >= 1000)
    return numberToWordsHelper(n / 1000) + " Thousand" + numberToWordsHelper(n % 1000);
    if (n >= 100) 
    return numberToWordsHelper(n / 100) + " Hundred" + numberToWordsHelper(n % 100);
    if (n >= 20) 
    return " " + ten[n / 10 - 2] + numberToWordsHelper(n % 10);
    if (n >= 1) 
    return " " + one[n - 1];
    
    return "";
}

string numberToWords(int num) {
    if (num == 0) return "Zero";
    return numberToWordsHelper(num).substr(1); 
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (num < 0 || num > 2147483647) {
        cout << "Number out of range. Please enter a number between 0 and 2147483647." << endl;
        return 1;
    }else{
    cout << numberToWords(num) << endl;
    }
    
    return 0;
}
