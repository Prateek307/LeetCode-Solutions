// link to the problem ---> https://leetcode.com/problems/single-number/submissions/1269676729/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int num = nums[0];
        int i;
        for (i = 1; i < nums.size(); i++)
            num ^= nums[i];
        return num;
    }
};