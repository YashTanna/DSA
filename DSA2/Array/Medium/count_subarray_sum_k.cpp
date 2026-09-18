#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> a, int k)
{
    int n = a.size();
    int prefixSum = 0, cnt = 0;
    unordered_map<int, int> map;
    map[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum += a[i];
        int rem = prefixSum - k;
        cnt += map[rem];
        map[prefixSum] += 1;
    }

    return cnt;
}

// void subarraySum(vector<int> a, int k)
{
    int n = a.size();
    int prefixSum = 0;

    unordered_map<int, vector<int>> mp;
    mp[0].push_back(-1);

    for (int i = 0; i < n; i++)
    {
        prefixSum += a[i];

        int rem = prefixSum - k;

        if (mp.find(rem) != mp.end())
        {
            for (int start : mp[rem])
            {
                cout << "[ ";
                for (int j = start + 1; j <= i; j++)
                {
                    cout << a[j] << " ";
                }
                cout << "]\n";
            }
        }

        mp[prefixSum].push_back(i);
    }
}

int main()
{
    // Input array
    // vector<int> arr = {3, 1, 2, 4};
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

    // Target sum
    int k = 6;

    // Call function and store result
    int result = subarraySum(arr, k);

    // Print the count of subarrays
    cout << "The number of subarrays is: " << result << "\n";

    // subarraySum(arr, k);
    return 0;
}