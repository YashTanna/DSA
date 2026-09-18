#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> a){
    int n = a.size();
    if(n == 0)
        return 0;
    int longest = 1;
    sort(a.begin(),a.end());   
    int cnt = 0;
    int lastSmaller = INT_MIN;
    for(int i = 0;i<n;i++){
        if(a[i] - 1 == lastSmaller){
            cnt++;
            lastSmaller = a[i];
        }else if(a[i] != lastSmaller){
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(cnt,longest);
    }

    return longest;
}

int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2,102,105,101,103,104}; 

    // Function call for finding longest consecutive sequence
    int ans = longestConsecutive(a); 
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}