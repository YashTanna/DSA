#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int my_partition(int a[], int low, int high)
{

    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {

        while (i <= high && a[i] <= pivot)
        {
            i++;
        }

        while (j >= low && a[j] > pivot)
        {
            j--;
        }

        if (i < j)
            swap(a[i], a[j]);
    }

    swap(a[low], a[j]);

    return j;
}

void quick_sort(int a[], int low, int high)
{

    if (low < high)
    {
        int pivotIndex = my_partition(a, low, high);

        quick_sort(a, low, pivotIndex - 1);

        quick_sort(a, pivotIndex + 1, high);
    }
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

    // Call quick sort
    quick_sort(arr, 0, n - 1);

    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}