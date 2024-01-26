// link to the problem ---> https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int i, len = 1, n = nums.size();
        for (i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
                len++;
        }
        return len;
    }
};