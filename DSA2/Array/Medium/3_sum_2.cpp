#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> a)
{
    vector<vector<int>> res;
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && a[i] == a[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = a[i] + a[j] + a[k];
            if (sum == 0)
            {
                res.push_back({a[i], a[j], a[k]});
                j++;
                k--;
                while (j < k && a[j] == a[j - 1])
                {
                    j++;
                }
                while(k > j && a[k] == a[k+1])
                    k--;
            }
            else if(sum < 0)
            {
                j++;
            }else{
                k--;
            }
        }
    }
    return res;
}

int main()
{
    // vector<int> nums = {2, -2, 0, 3, -3, 5};
    vector<int> nums = {2, -2, 0, 3, -3, 5};

    vector<vector<int>> answer = threeSum(nums);

    for (const auto &triplet : answer)
    {
        for (int value : triplet)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}