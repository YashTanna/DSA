#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumIndices(vector<int> a, int target)
{
    unordered_map<int,int> mp;
    int n = a.size();

    for(int i=0;i<n;i++){

        int comp = target - a[i];
        if(mp.find(comp) != mp.end())
            return {mp[comp],i};

        mp[a[i]] = i;
    }
    return {-1,-1};
}

int main()
{

    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 16;

    // cout << twoSumExists(arr, target) << "\n";
    vector<int> res = twoSumIndices(arr, target);
    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}