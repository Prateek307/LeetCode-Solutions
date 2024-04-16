// link to the problem ---> https://leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0, j = i + 1;
        sort(nums.begin(), nums.end());
        while (j < nums.size())
        {
            if (nums[i] == nums[j])
                return nums[i];
            i++;
            j++;
        }
        return 0;
    }
};