// link to the problem ---> https://leetcode.com/problems/insert-interval/description/

#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int a = newInterval[0], b = newInterval[1];
        int i = 0, n = intervals.size();

        // Insert intervals before the new interval or non-overlapping intervals
        for (; i < n && intervals[i][1] < a; i++)
            ans.push_back(intervals[i]);

        // Merge overlapping intervals
        for (; i < n && intervals[i][0] <= b; i++)
        {
            a = min(a, intervals[i][0]);
            b = max(b, intervals[i][1]);
        }

        ans.push_back({a, b}); // Insert the merged interval

        // Insert the remaining intervals
        ans.reserve(ans.size() + intervals.size() - i);
        ans.insert(ans.end(), intervals.begin() + i, intervals.end());

        return ans;
    }
};
