#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int a1[], int a2[], int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> result;
    while (i < n && j < m)
    {
        if (a1[i] < a2[j])
        {

            if (result.empty() || result.back() != a1[i])
            {
                result.push_back(a1[i]);
            }
            i++;
        }
        else if (a2[j] < a1[i])
        {
            if (result.empty() || result.back() != a2[j])
            {
                result.push_back(a2[j]);
            }
            j++;
        }
        else
        {
            if (result.empty() || result.back() != a1[i])
            {
                result.push_back(a1[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (result.empty() || result.back() != a1[i])
            result.push_back(a1[i]);
        i++;
    }

    // Append remaining elements from arr2
    while (j < m)
    {
        if (result.empty() || result.back() != a2[j])
            result.push_back(a2[j]);
        j++;
    }

    return result;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = 10, m = 7;

    vector<int> result = findUnion(arr1, arr2, n, m);

    cout << "Union of arr1 and arr2 is: ";
    for (int val : result)
        cout << val << " ";
    return 0;
}