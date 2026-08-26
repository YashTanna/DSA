#include <bits/stdc++.h>
using namespace std;

int search(int a[],int n,int num){
    for(int i=0;i<n;i++){
        if(a[i] == num)
            return i;
    }
    return -1;
}

int main()
{
    // Declare and initialize the array
    int arr[] = {1, 2, 3, 4, 5};

    // Number to search for
    int num = 4;

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the search function and store the result
    int val = search(arr, n, num);

    // Print the index of the found number or -1 if not found
    printf("%d", val);

    return 0;
}