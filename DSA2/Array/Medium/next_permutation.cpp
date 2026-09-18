#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &a){
    int n = a.size();
    int ind = -1;

    for(int i=n-2;i>=0;i--){
        if(a[i] < a[i+1]){
            ind = i;
            break;
        }
    }

    if(ind == -1){
        reverse(a.begin(),a.end());
        return;
    }

    for(int i=n-1;i>ind;i--){
        if(a[i] > a[ind]){
            swap(a[i],a[ind]);
            break;
        }
    }

    reverse(a.begin() + ind + 1,a.end());
}

int main() {
    // Input array
    vector<int> nums = {3,2,1};

    // Call the function
    nextPermutation(nums);

    // Print result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}