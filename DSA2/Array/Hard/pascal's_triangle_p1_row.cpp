#include <bits/stdc++.h>
using namespace std;

vector<long long> getNthRow(int n)
{
    vector<long long> res;
    res.push_back(1);
    long long ans = 1;

    for (int i = 1; i < n; i++)
    {
        ans *= (n - i);
        ans /= i;
        res.push_back(ans);
    }
    return res;
}

int main()
{
    int N = 5; // Example: 5th row

    vector<long long> result = getNthRow(N);

    // Print the row
    for (auto num : result)
    {
        cout << num << " ";
    }
    return 0;
}