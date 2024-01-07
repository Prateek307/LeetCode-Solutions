// link to the problem --> https://leetcode.com/problems/contains-duplicate-ii/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0 || k <= 0)
        {
            return false; // No duplicates possible
        }

        std::map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            auto it = m.find(nums[i]);
            if (it != m.end() && i - it->second <= k)
            {
                return true;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
