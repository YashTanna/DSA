#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &a, int target)
    {
        int n = a.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }

    int findSmallerOrEqual(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += upperBound(mat[i], x);
        }
        return cnt;
    }

    int findMedian(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }
        int req = (n * m) / 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int smallEqual = findSmallerOrEqual(mat, mid);
            if (smallEqual <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};

    Solution obj;
    cout << obj.median(mat) << endl;

    return 0;
}