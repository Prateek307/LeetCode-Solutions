// link to the problem ---> https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
                return i;
        }
        return i;
    }
};