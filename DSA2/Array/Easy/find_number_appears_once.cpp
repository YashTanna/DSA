#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr){
    int xor1 = 0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        xor1 ^= arr[i];
    }

    return xor1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2, 4, 5};

    int ans = getSingleElement(arr);

    cout << "The single element is: " << ans << endl;

    return 0;
}