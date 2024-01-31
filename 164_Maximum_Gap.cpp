// link to the problem ---> https://leetcode.com/problems/maximum-gap/

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int i, mn = INT_MIN;
        for (i = 1; i < nums.size(); i++)
        {
            mn = max(mn, nums[i] - nums[i - 1]);
        }
        return mn;
    }
};