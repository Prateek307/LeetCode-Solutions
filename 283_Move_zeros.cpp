// link to the problem ---> https://leetcode.com/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int cnt = 0, i, n = nums.size();
        vector<int> temp;
        for (i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                cnt++;
            else
                temp.push_back(nums[i]);
        }
        for (i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }
        for (i = temp.size(); i < n; i++)
        {
            nums[i] = 0;
        }
    }
};