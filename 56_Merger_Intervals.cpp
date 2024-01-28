// link to the problem ---> https://leetcode.com/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(intervals.begin(), intervals.end());
        v.push_back(intervals[0][0]);
        v.push_back(intervals[0][1]);
        ans.push_back(v);
        int i = 1, n = intervals.size();
        while (i < n)
        {
            if (intervals[i][0] > v[1])
            {
                v.clear();
                v.push_back(intervals[i][0]);
                v.push_back(intervals[i][1]);
                ans.push_back(v);
            }
            else
            {
                if (intervals[i][0] <= v[0])
                {
                    ans.pop_back();
                    v.pop_back();
                    v.pop_back();
                    v.push_back(intervals[i][0]);
                    v.push_back(intervals[i][1]);
                    ans.push_back(v);
                }
                else
                {
                    if (intervals[i][1] > v[1])
                    {
                        ans.pop_back();
                        v.pop_back();
                        v.push_back(intervals[i][1]);
                        ans.push_back(v);
                    }
                }
            }
            i++;
        }
        return ans;
    }
};