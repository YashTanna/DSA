#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &a,int k){
    int n = a.size();
    vector<int> howMany(n-1,0);
    for(int station = 0;station < k; station++){
        long double maxSection = -1;
        int maxIndex = -1;
        for(int i=0;i<n-1;i++){
            int diff = a[i+1] - a[i];
            long double sectionDiff = diff / (long double) (howMany[i] + 1);
            if(sectionDiff > maxSection){
                maxSection = sectionDiff;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }
    long double maxAns = -1;
    for(int i=0;i<n-1;i++){
        long double diff = a[i+1] - a[i];
        long double maxSection = diff / (howMany[i] + 1);
        maxAns = max(maxSection, maxAns);
    }
    return maxAns;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}