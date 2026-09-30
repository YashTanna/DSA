#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> a)
{
    int n = a.size();
    int cnt1 = 0, cnt2 = 0;
    int el1, el2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && a[i] != el2)
        {
            cnt1 = 1;
            el1 = a[i];
        }
        else if (cnt2 == 0 && a[i] != el1)
        {
            cnt2 = 1;
            el2 = a[i];
        }
        else if (a[i] == el1)
            cnt1++;
        else if (a[i] == el2)
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int cnt1Final = 0, cnt2Final = 0;

    for (int x : a)
    {
        if (x == el1)
            cnt1Final++;
        else if (x == el2)
            cnt2Final++;
    }

    vector<int> temp;

    if (cnt1Final > n / 3)
        temp.push_back(el1);

    if (cnt2Final > n / 3)
        temp.push_back(el2);

    return temp;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 1, 2, 4, 2, 1};

    vector<int> answer = majorityElement(nums);

    // Print every qualifying value returned by the solution.
    for (int value : answer)
    {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}