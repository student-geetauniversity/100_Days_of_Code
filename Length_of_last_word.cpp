#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s) {
        int n=s.size();
        int first;
        char ch = ' ';
        for(int i=n-1;i>=0;i--){
            if(s[i] != ch){
                first=i;
                break;
            }
        }
        int count=0;
        for(int i=first; i>=0; i--){
            if(s[i] == ch)
            break;
            count++;
        }
        return count;
    }
int main(){
    string s;
    getline(cin,s);
    cout << "Length of Last word in String is : " << lengthOfLastWord(s) << endl;
    return 0;
}

