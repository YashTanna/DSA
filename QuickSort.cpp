#include <iostream>
#include <string>
using namespace std;

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (!(a[i] > pivot));
        do
        {
            j--;
        } while (!(a[j] <= pivot));
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);

    swap(a[l], a[j]);

    return j;
}

void QuickSort(int a[],int l,int h)
{
    if(l<h)
    {
        int j = partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
main()
{
    int a[] = {1, 8, 6, 5, 3, 9, 2, 7, 4, 10, INT32_MAX}, n = 10;

    QuickSort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}