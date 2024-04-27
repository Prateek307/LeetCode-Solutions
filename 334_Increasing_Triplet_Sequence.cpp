// link to the problem ---> https://leetcode.com/problems/increasing-triplet-subsequence/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first_small = INT_MAX;
        int second_small = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= first_small)
                first_small = nums[i];
            else if (nums[i] <= second_small)
                second_small = nums[i];
            else
                return true;
        }
        return false;
    }
};