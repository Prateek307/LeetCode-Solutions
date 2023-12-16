// link to the problem ---> https://leetcode.com/problems/valid-anagram/description/?envType=daily-question&envId=2023-12-16

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> m1, m2;
        if (s.size() != t.size())
            return 0;
        int i = 0;
        while (i < s.size())
        {
            m1[s[i]]++;
            i++;
        }
        i = 0;
        while (i < t.size())
        {
            auto it = m1.find(t[i]);
            if (it == m1.end())
                return 0;
            m2[t[i]]++;
            i++;
        }
        i = 0;
        while (i < t.size())
        {
            if (m1[t[i]] != m2[t[i]])
                return 0;
            i++;
        }
        return 1;
    }
};