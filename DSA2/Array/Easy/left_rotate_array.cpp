#include <bits/stdc++.h>
using namespace std;

void rotateArrayByOne(vector<int> &a){
    int temp = a[0];

    for(int i=1;i<a.size();i++){
        a[i-1] = a[i];
    }

    a[a.size()-1] = temp;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    rotateArrayByOne(nums);

    for (int num : nums) {
        cout << num << " "; // Output the rotated array
    }

    return 0;
}