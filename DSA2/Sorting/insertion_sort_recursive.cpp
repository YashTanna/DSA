#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(int a[], int n, int i)
{
    if (i == n)
        return;

    int j = i;
    while (j > 0 && a[j] < a[j - 1])
    {
        swap(a[j], a[j - 1]);
        j--;
    }

    insertion_sort(a, n, i + 1);
}

int main()
{

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
    insertion_sort(arr, n, 0);

    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}