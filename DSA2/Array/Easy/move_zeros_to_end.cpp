#include <bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void moveZeroes(vector<int> &a) {
    int insertPos = 0;

    for(int i=0;i<a.size();i++){
        if(a[i] != 0){
            swap(a[insertPos],a[i]);
            insertPos++;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 2,0,0,0,21,5,2,3,0,0,0,0};
    moveZeroes(nums);

    // Print the result
    for (int num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}