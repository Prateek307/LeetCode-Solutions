// link to the problem ---> https://leetcode.com/problems/subsets/description/

class Solution
{
public:
    void solve(int i, vector<int> &nums, vector<int> &ans, set<vector<int>> &st)
    {
        if (i == nums.size())
        {
            st.insert(ans);
            return;
        }

        ans.push_back(nums[i]);
        solve(i + 1, nums, ans, st);
        ans.pop_back();
        solve(i + 1, nums, ans, st);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        set<vector<int>> st;
        vector<int> ans;
        solve(0, nums, ans, st);

        vector<vector<int>> res;
        for (auto it : st)
            res.push_back(it);

        return res;
    }
};
