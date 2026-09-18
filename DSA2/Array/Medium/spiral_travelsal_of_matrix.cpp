#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();
    vector<int> result;

    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(a[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(a[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(a[bottom][i]);
            }
            bottom--;
        }
        if (top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(a[i][left]);
            }
            left++;
        }
    }

    return result;
}

// Driver code
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11},
    };

    cout << "Original matrix" << endl;

    for (auto row : matrix)
    {
        for (int val : row)
            cout << val << "  ";
        cout << endl;
    }

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Traversal" << endl;

    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}