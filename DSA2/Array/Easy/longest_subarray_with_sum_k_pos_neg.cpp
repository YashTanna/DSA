#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> a,int k){
    map<int,int> preSum;
    int sum = 0;
    int n = a.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }

        int rem = sum - k;
        if(preSum.find(rem) != preSum.end()){
            int len = i - preSum[rem];
            maxLen = max(len,maxLen);
        }
        if(preSum.find(rem) == preSum.end()){
            preSum[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> a = { -1, 1, 1 };
    int k = 1;

    int len = getLongestSubarray(a, k);

    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}