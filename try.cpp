#include <iostream>
#include <string>
using namespace std;

int a[] = {6, 5, 8, 9, 3, 10, 15, 12, 16, 1000};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int l, int h)
{
    int pivot = a[l];
    int i = l;
    int j = h;


    do
    {
        i++;
    } while (a[i] > pivot);

    do
    {
        j--;
    } while (a[j] < pivot);

    if(i<j)
        swap(a[i],a[j]);
    else
        swap(a[l],a[j]);

    
}

void QuickSort(int l, int h)
{
    if (l < h)
    {
        int j = Partition(l, h);
        QuickSort(l, j);
        QuickSort(j + 1, h);
    }
}

int main() // Corrected the return type of main to 'int'.
{
    QuickSort(0, 9); // You should pass indices 0 and 9 instead of array values.

    for (int i = 0; i < 10; i++) // Changed the loop condition to iterate 10 times.
    {
        cout << a[i] << " "; // Added space for better output formatting.
    }
    return 0;
}
