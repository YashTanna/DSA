#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> a)
{
    int n = a.size();

    int cnt = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = a[i];
        }
        else if (a[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    return ele;
}

int main()
{
    vector<int> arr = {5, 52, 2, 5, 5, 1, 5, 5, 5, 1, 1, 5, 2, 5, 2, 5, 5};

    int ans = majorityElement(arr);

    // Print the majority element found
    cout << "The majority element is: " << ans << endl;

    return 0;
}