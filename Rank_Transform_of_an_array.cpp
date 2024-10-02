#include<bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    set<int> st(begin(arr), end(arr));

    int rankNumber = 1;
    unordered_map<int, int> rank;
    for (int value : st)
        rank[value] = rankNumber++;

    for (int &value : arr)
        value = rank[value];
    
    return arr;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result = arrayRankTransform(arr);
    
    cout << "Rank transformed array: ";
    for(int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
