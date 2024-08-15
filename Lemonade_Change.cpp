#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills){
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) 
              five++;
            else if (bill == 10) {
                if (five == 0) 
                   return false;
                five--;
                ten++;
            }
            else {
                if (ten > 0) {
                    ten--;
                    five--;
                }
                else{
                    five -= 3;
                }
                if (five < 0)
                  return false;
            }
        }
        return true;
    }
    
int main()
{
    int n ;
    cout << "Enter size of bills : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter elements in bills : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    if(lemonadeChange(arr)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;
}
