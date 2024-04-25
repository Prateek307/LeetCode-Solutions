// link to the problem ---> https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    void solve(vector<int> v, int n, set<vector<int>> &output, int target, int i, vector<int> ans)
    {
        if (i == n)
        {
            if (target == 0)
            {
                sort(ans.begin(), ans.end());
                output.insert(ans);
            }
            return;
        }
        // we can decide either to pick the index or not
        if (v[i] <= target) // if this condition holds true then we will pick the index
        {
            ans.push_back(v[i]);
            solve(v, n, output, target - v[i], i, ans);
            ans.pop_back();
        }
        // if we are not picking up the index
        solve(v, n, output, target, i + 1, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        v = candidates;
        int n = v.size();
        set<vector<int>> output;
        vector<int> ans;
        solve(v, n, output, target, 0, ans);
        vector<vector<int>> res;
        for (auto i : output)
        {
            res.push_back(i);
        }
        return res;
    }
};