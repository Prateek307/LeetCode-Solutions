// link to the problem ---> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i, j, n = s.size(), mx = INT_MIN, sz;
        bool flag = 0;
        if (s == "")
            return 0;
        if (s.size() == 1)
            return 1;
        map<char, int> m;
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                auto it = m.find(s[j]);
                if (it == m.end()) // it means element is repeated
                {
                    m[s[j]]++;
                }
                else
                {
                    sz = m.size();
                    mx = max(mx, sz);
                    m.clear();
                    break;
                }
            }
        }
        return mx;
    }
};