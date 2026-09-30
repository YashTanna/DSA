#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> a){
    int n = a.size();
    set<vector<int>> pairs;
    for(int i =0;i<n-1;i++){
        unordered_set<int> seen;
        for(int j=i+1;j<n;j++){
            int rem = - (a[i] + a[j]);
            if(seen.find(rem) != seen.end()){
                vector<int> temp = {a[i],a[j],(int) rem};
                sort(temp.begin(),temp.end());
                pairs.insert(temp);
            }

            seen.insert(a[j]);
        }
    }
    return vector<vector<int>>(pairs.begin(),pairs.end());
}

int main() {
    vector<int> nums = {2, -2, 0, 3, -3, 5};

    vector<vector<int>> answer = threeSum(nums);

    for (const auto& triplet : answer) {
        for (int value : triplet) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}