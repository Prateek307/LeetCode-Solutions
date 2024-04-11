// link to the problem ---> https://leetcode.com/problems/majority-element-ii/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int i;
        map<int, int> m;
        int n = nums.size();
        for (i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        vector<int> ans;
        int fre = floor(n / 3);
        for (auto it : m)
        {
            if (it.second > fre)
                ans.push_back(it.first);
        }
        return ans;
    }
};