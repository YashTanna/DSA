#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, maxCount = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            if (count > maxCount)
                maxCount = count;
            count = 0;
        }
    }

    if (count > maxCount)
        maxCount = count;

    return maxCount;
}

int main()
{
    // Input array
    vector<int> nums = {1, 1, 1, 1, 0, 1};

    // Get answer
    int ans = findMaxConsecutiveOnes(nums);

    // Print result
    cout << "The maximum consecutive 1's are " << ans;
    return 0;
}