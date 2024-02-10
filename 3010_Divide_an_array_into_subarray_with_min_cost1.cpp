// link to the problem --->https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int val1 = nums[0];
        sort(nums.begin() + 1, nums.end());
        return val1 + nums[1] + nums[2];
    }
};