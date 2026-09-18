#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int sum = nums[0];
    int n = nums.size();
    int maxLen = 0;
    int left = 0, right = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
            sum -= nums[left++];

        if (sum == k)
            maxLen = max(maxLen, (right - left + 1));

        right++;
        if (right < n)
            sum += nums[right];
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    /* Function call to find the length
    of longest subarray having sum k */
    int ans = longestSubarray(nums, k);

    cout << "The length of longest subarray having sum k is: " << ans;

    return 0;
}