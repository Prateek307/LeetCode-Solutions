// link to the problem ---> https://leetcode.com/problems/neither-minimum-nor-maximum/

class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() >= 3)
            return nums[1];
        return -1;
    }
};