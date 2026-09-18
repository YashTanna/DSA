#include <bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    int ans = 1;
    for(int i=0;i<r;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

int findPascalElement(int r, int c){
    return nCr(r-1,c-1);
}

int main() {
    int r = 5, c = 3;
    cout << findPascalElement(r, c);
    return 0;
}