#include<iostream>
#include<string>
using namespace std;

void BubbleSort(int a[],int n);

void swap(int & a,int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

main()
{
    int a[] = {1,8,6,5,3,9,2,7,4,10};
    BubbleSort(a,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void BubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}