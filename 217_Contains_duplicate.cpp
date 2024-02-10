// link to the problem ---> https://leetcode.com/problems/contains-duplicate/description/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i, n = nums.size();
        for (i = 0; i < n - 1; i++)
        {
            bool val = 0;
            val = nums[i] ^ nums[i + 1];
            if (!val)
                return 1;
        }
        return 0;
    }
};