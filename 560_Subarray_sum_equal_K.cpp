// link to the problem ---> https://leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int i, j, ans = 0, sum = 0, n = nums.size();
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};