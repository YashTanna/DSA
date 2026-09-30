#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> fourSum(vector<int> a, int target)
// {
//     int n = a.size();
//     vector<vector<int>> res;
//     sort(a.begin(), a.end());
//     for (int i = 0; i < n; i++)
//     {
//         if (i > 0 && a[i] == a[i - 1])
//             continue;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (j != i + 1 && a[j] == a[j - 1])
//                 continue;
//             int k = j + 1;
//             int l = n - 1;

//             while (k < l)
//             {
//                 long long sum = a[i] + a[j];
//                 sum += a[k];
//                 sum += a[l];
//                 if (sum < target)
//                 {
//                     k++;
//                 }
//                 else if (sum > target)
//                 {
//                     l--;
//                 }
//                 else
//                 {
//                     res.push_back({a[i], a[j], a[k++], a[l--]});
//                     while (k < l && a[k] == a[k - 1])
//                         k++;

//                     while (k < l && a[l] == a[l + 1])
//                         l--;
//                 }
//             }
//         }
//     }
//     return res;
// }

vector<vector<int>> fourSum(vector<int> a, int target)
{
    int n = a.size();
    vector<vector<int>> res;

    sort(a.begin(), a.end()); // missing

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && a[j] == a[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = a[i] + a[j];
                sum += a[k];
                sum += a[l];

                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    res.push_back({a[i], a[j], a[k++], a[l--]});

                    while (k < l && a[k] == a[k - 1])
                        k++;

                    while (k < l && a[l] == a[l + 1])
                        l--;
                }
            }
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {1, -2, 3, 5, 7, 9};
    int target = 7;

    vector<vector<int>> answer = fourSum(nums, target);

    for (const auto &quadruplet : answer)
    {
        for (int value : quadruplet)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}