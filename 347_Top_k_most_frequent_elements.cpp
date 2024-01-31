// link to  the problem ---> https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        map<int, int> m;
        int n = nums.size();
        int i;
        for (i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto it : m)
        {
            // first will hold the frequency
            // second will hold the value
            int x = it.second; // fre
            int y = it.first;  // val
            v.push_back(make_pair(x, y));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        i = 0;
        while (k--)
        {
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};