#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[],int n){
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1])
            return false;
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 6, 4, 5}, n = 5;
    printf("%s", isSorted(arr, n) ? "True" : "False");  // Output result
}