// link to the problem ---> https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st;
        int i;
        if (nums.size() == 0)
            return 0;
        for (i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        vector<int> temp;
        for (auto it : st)
            temp.push_back(it);
        int n = temp.size();
        int cnt = 1, ans = 1;
        for (i = 1; i < n; i++)
        {
            if (temp[i] == temp[i - 1] + 1)
            {
                cnt++;
                ans = max(cnt, ans);
            }
            else
            {
                ans = max(cnt, ans);
                cnt = 1;
            }
        }
        return ans;
    }
};