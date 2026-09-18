#include <bits/stdc++.h>
using namespace std;

// If row index start from 0
// vector<int> generateRaw(int row)
// {
//     vector<int> resRow;
//     long long ans = 1;
//     resRow.push_back(ans);
//     for (int col = 1; col <= row; col++)
//     {
//         ans = ans * (row - col + 1);
//         ans = ans / col;
//         resRow.push_back(ans);
//     }
//     return resRow;
// }

// If row index start from 1
vector<int> generateRaw(int row)
{
    vector<int> resRow;
    long long ans = 1;
    resRow.push_back(ans);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        resRow.push_back(ans);
    }
    return resRow;
}

vector<vector<int>> generate(int n)
{
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(generateRaw(i));
    }
    return res;
}

int main()
{
    int n = 5;
    vector<vector<int>> result = generate(n);

    for (int i = 0; i < n; i++)
    {
        // Print leading spaces for pyramid alignment
        for (int s = 0; s < n - 1 - i; s++)
        {
            cout << " ";
        }

        // Print each number followed by a space
        for (int val : result[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}