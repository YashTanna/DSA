#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(vector<int> &a, int start, int end)
{
    while (start < end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}

vector<int> rotateArray(vector<int> &nums, int k, string dir)
{
    int n = nums.size();
    if (n == 0 || k == 0)
        return nums;
    if (dir == "right")
    {
        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
    else if (dir == "left")
    {
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
        reverseArray(nums, 0, n - 1);
    }

    return nums;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    string dir = "left";

    vector<int> result = rotateArray(nums, k, dir);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}