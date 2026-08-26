#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &n)
{

    int i = 0;

    for (int j = 1; j < n.size(); j++)
    {
        if (n[i] != n[j])
        {
            i++;
            n[i] = n[j];
        }
    }

    return i + 1;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums);

    cout << "Unique count = " << k << "\n";
    cout << "Array after removing duplicates: ";
    for (int x = 0; x < k; x++)
    {
        cout << nums[x] << " ";
    }
    cout << endl;
}