#include <bits/stdc++.h>
using namespace std;

// Using formula of sum of first N number

// int missingNum(vector<int> &a)
// {
//     int n = a.size() + 1;
//     int sum = 0;
//     for (int i = 0; i < n - 1; i++)
//         sum += a[i];

//     long long expectedSum = ((n * 1LL * (n + 1)) / 2);

//     return expectedSum - sum;
// }

// using XOR

int missingNum(vector<int> &a)
{
    int xor1 = 0, xor2 = 0;
    int n = a.size() + 1;

    for(int i=0;i<n-1;i++)
        xor1 ^= a[i];
    
    for(int i=1;i<=n;i++)
        xor2 ^= i;
    
    return xor1^xor2;
}


int main()
{
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1};
    cout << missingNum(arr);
    return 0;
}