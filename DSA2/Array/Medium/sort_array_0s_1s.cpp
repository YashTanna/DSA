// Dutch National Flag algorithm

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortZeroOneTwo(vector<int> &a)
{
    int n = a.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[mid], a[low]);
            mid++;
            low++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0, 1, 2, 1, 2, 2, 0};

    sortZeroOneTwo(nums);

    for (int val : nums)
        cout << val << " ";

    return 0;
}