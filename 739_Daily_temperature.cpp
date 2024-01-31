// link to the problem ---> https://leetcode.com/problems/daily-temperatures/submissions/1161857796/?envType=daily-question&envId=2024-01-31

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int i, n = temperatures.size(), hottest = INT_MIN;
        vector<int> ans(n, 0);
        for (i = n - 1; i >= 0; i--)
        {
            if (temperatures[i] >= hottest)
                hottest = temperatures[i];
            else
            {
                int it = i + 1;
                while (temperatures[it] <= temperatures[i])
                {
                    it += ans[it];
                }
                ans[i] = it - i;
            }
        }
        return ans;
    }
};