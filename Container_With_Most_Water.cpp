#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxArea = 0;
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int currArea = minHeight * (right - left);
            maxArea = max(maxArea, currArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
    return maxArea;
}
int main(){
    int n ;
    cout << "Enter Length : ";
     cin >> n;
    vector<int> arr(n);
    cout << "Enter the Heights : ";
     for(int i=0;i<n;i++){
         cin >> arr[i];
     }
     
     int result = maxArea(arr);
     cout << "the max area of water the container can contain is " << result << endl;
    
    return 0;
}
