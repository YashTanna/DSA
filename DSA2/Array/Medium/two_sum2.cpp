#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumIndices(vector<int> a, int target)
{
    int n = a.size();

    vector<pair<int, int>> indexs;

    for (int i = 0; i < n; i++)
    {
        indexs.push_back({a[i], i});
    }

    sort(indexs.begin(), indexs.end());

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = indexs[left].first + indexs[right].first;
        if (sum < target)
            left++;
        else if (sum > target)
            right--;
        else if (sum == target)
            return {indexs[left].second, indexs[right].second};
    }
    return {-1, -1};
}

int main()
{

    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 16;

    // cout << twoSumExists(arr, target) << "\n";
    vector<int> res = twoSumIndices(arr, target);
    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}