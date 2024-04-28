// link to the problem ---> https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int st = 0, end = nums.size() - 1, count = 0;
        while (st < end)
        {
            if ((nums[st] + nums[end]) == k)
            {
                count++;
                st++;
                end--;
            }
            else if ((nums[st] + nums[end]) > k)
            {
                end--;
            }
            else
            {
                st++;
            }
        }
        return count;
    }
};