#include <bits/stdc++.h>
using namespace std;

int findLargestElement(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int main()
{
    // Array 1
    int arr1[] = {2, 5, 1, 3, 0};
    int n = 5;                                                      // Size of the array
    int max = findLargestElement(arr1, n);                          // Call the function to find the largest element
    cout << "The largest element in the array is: " << max << endl; // Output the result

    // Array 2
    int arr2[] = {8, 10, 15, 7, 9};
    n = 5;                                                          // Size of the array
    max = findLargestElement(arr2, n);                              // Call the function to find the largest element
    cout << "The largest element in the array is: " << max << endl; // Output the result

    return 0;
}