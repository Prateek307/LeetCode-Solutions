// link to the problem ---> https://leetcode.com/problems/combinations/description/

class Solution
{
public:
    void solve(int i, int n, int k, vector<int> &ans, vector<vector<int>> &res)
    {
        if (i == n + 1)
        {
            if (k == 0)
                res.push_back(ans);
            return;
        }

        ans.push_back(i);
        solve(i + 1, n, k - 1, ans, res);
        ans.pop_back();
        solve(i + 1, n, k, ans, res);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> ans;
        solve(1, n, k, ans, res);
        return res;
    }
};