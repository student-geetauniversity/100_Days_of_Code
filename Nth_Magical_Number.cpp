#include <bits/stdc++.h>
using namespace std;

  long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
        
 long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }
    
int nthMagicalNumber(int n, int a, int b) {
        long long lcm_ab = lcm((long long)a, (long long)b);
        long long low = 1, high = 1e14;
        long long mod = 1e9 + 7;
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long count = mid / a + mid / b - mid / lcm_ab;
            
            if (count < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low % mod;
    }
    

   

int main() {
    int n, a, b;
    
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << "Enter the value of a: ";
    cin >> a;
    
    cout << "Enter the value of b: ";
    cin >> b;
    
    int result = nthMagicalNumber(n, a, b);
    cout << "Nth magical number: " << result << endl;
    
    return 0;
}
