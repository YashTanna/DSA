#include <bits/stdc++.h>
using namespace std;

// Finds the maximum sum
// int maxSubArray(vector<int> a){
//     int sum = 0;
//     int maxSum = INT_MIN;
//     int n = a.size();

//     for(int i=0;i<n;i++){
//         sum += a[i];

//         if(sum > maxSum)
//             maxSum = sum;

//         if(sum < 0)
//             sum = 0;
//     }
//     return maxSum;
// }

// Finds the maximum sum and also prints the sub array
int maxSubArray(vector<int> a)
{

    int sum = 0, maxSum = INT_MIN, start = 0, ansStart = -1, ansEnd = -1;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            // Reset the start index
            start = i;
        }

        sum += a[i];
        
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
            sum = 0;
    }

    // Printing the subarray
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << a[i] << " ";
    }
    cout << "]" << endl;

    return maxSum;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxSum = maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}