#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeBySign(vector<int> a){
    vector<int> ans(a.size());

    int pos = 0;
    int neg = 1;

    for(int i : a){
        if(i < 0){
            ans[neg] = i;
            neg = neg + 2; 
        }else{
            ans[pos] = i;
            pos = pos + 2;
        }
    }

    return ans;
}

int main() {
    // Initialize the input array
    vector<int> A = {1, 2, -4, -5,-7,-10,10,7};

    // Call the rearrange function
    vector<int> result = rearrangeBySign(A);

    // Print the rearranged array
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}