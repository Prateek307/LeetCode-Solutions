// link to the problem ---> https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int i = 0, n = nums.size(), j = 0;
        vector<int> minus;
        vector<int> ans;
        for (auto it : nums)
        {
            if (it < 0)
                minus.push_back(it);
        }
        while (i < n)
        {
            if (nums[i] < 0)
                i++;
            else
            {
                ans.push_back(nums[i]);
                if (j < minus.size())
                    ans.push_back(minus[j]);
                i++;
                j++;
            }
        }
        return ans;
    }
};