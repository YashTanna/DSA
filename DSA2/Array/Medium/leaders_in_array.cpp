#include <bits/stdc++.h>
using namespace std;

// Leader element in the array is the one which is greater then all the element of right sub array.

vector<int> leaders(vector<int> a){
    int n = a.size();
    int max = INT_MIN;
    vector<int> leader;

    for(int i=n-1;i>=0;i--){
        if(a[i] > max){
            leader.push_back(a[i]);
            max = a[i];
        }
    }

    return leader;
}

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};
    
    // Get leaders using class method
    vector<int> ans = leaders(nums);
    
    cout << "Leaders in the array are: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}