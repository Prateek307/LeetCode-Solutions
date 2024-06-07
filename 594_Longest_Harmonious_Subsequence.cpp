// link to the problem ----> https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        int maxi = 0;

        while (right < nums.size())
        {

            if (nums[right] - nums[left] == 1)
            {
                int cnt = right - left + 1;
                maxi = max(maxi, cnt);
            }
            else if (nums[right] - nums[left] > 1)
            {
                while (nums[right] - nums[left] > 1)
                    left++;
            }
            right++;
        }
        return maxi;
    }
};