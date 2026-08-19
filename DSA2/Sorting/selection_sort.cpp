#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sorted = i;
        for (int j = sorted + 1; j < n; j++)
        {
            if (arr[j] < arr[sorted])
            {
                sorted = j;
            }
        }
        int temp = arr[sorted];
        arr[sorted] = arr[i];
        arr[i] = temp;
    }
    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // Initialize array
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print array before sorting
    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    selection_sort(arr, n);

    return 0;
}