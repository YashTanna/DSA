#include <bits/stdc++.h>
using namespace std;

int find2ndLargestElement(int a[], int n)
{
    if (n < 2)
        return -1;

    int max = INT_MIN;
    int max2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max2)
        {
            if (a[i] > max)
            {
                max2 = max;
                max = a[i];
            }
            else if (a[i] > max2 && a[i] != max)
            {
                max2 = a[i];
            }
        }
    }

    return (max2==INT_MIN? -1 : max2);
}

int main()
{
    // Array 1
    int arr1[] = {2, 5, 1, 6, 0};
    int n = 5;                                                          // Size of the array
    int max = find2ndLargestElement(arr1, n);                           // Call the function to find the largest element
    cout << "The 2nd largest element in the array is: " << max << endl; // Output the result

    // Array 2
    int arr2[] = {8, 10, 15, 7, 20};
    n = 5;                                                              // Size of the array
    max = find2ndLargestElement(arr2, n);                               // Call the function to find the largest element
    cout << "The 2nd largest element in the array is: " << max << endl; // Output the result

    return 0;
}