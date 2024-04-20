// link to the problem ---> https://leetcode.com/problems/longest-uncommon-subsequence-i/description/

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b)
            return -1;
        else
        {
            if (a.size() > b.size())
                return a.size();
            return b.size();
        }
    }
};