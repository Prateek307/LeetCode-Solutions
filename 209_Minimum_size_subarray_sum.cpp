// link to the problem ----> https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, sum = 0, n = nums.size(), ans = INT_MAX, l = 0;
        while (i < n)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(ans, i - l + 1);
                sum -= nums[l];
                l++;
            }
            i++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};