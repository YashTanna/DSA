#include<iostream>
#include<string>
using namespace std;

void Insertion(int a[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        x = a[i];
        j = i-1;
        while(j > -1 && a[j] > x )
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void swap(int & a,int & b)
{
    int temp = a;
    a = b;
    b = temp;
}
main()
{
    int a[] = {1,8,6,5,3,9,2,7,4,10},n=10;

    Insertion(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}