#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> a){
    int longest = 1;
    int n = a.size();
    if(n == 0)
        return 0;
    unordered_set<int> set;
    for(int i : a)
        set.insert(i);

    for(auto it : set){
        if(set.find(it-1) == set.end()){
            int cnt = 1;
            int x = it;
            while(set.find(x+1) != set.end()){
                cnt++;
                x = x + 1;
            }
            longest = max(longest,cnt);
        }
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