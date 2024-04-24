// link to the problem ---> https://leetcode.com/problems/count-the-number-of-special-characters-i/


class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        set<char> st;
        for (auto it : word)
            st.insert(it);
        string s;
        int ans = 0;
        for (auto it : st)
        {
            s.push_back(it);
        }

        int i;
        for (i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 97 && s[i] <= 122) && st.find(toupper(s[i])) != st.end())
                ans++;
        }
        return ans;
    }
};