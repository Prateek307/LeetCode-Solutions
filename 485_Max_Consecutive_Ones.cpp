// link to the problem ---> https://leetcode.com/problems/max-consecutive-ones/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int i, ans = 0, cnt = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};