// link to the problem ---> https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isSubsequence(const string &s1, const string &s2)
    {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size())
        {
            if (s1[i] == s2[j++])
            {
                i++;
            }
        }
        return i == s1.size();
    }

    int findLUSlength(vector<string> &strs)
    {
        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            bool isUnique = true;
            for (int j = 0; j < n; j++)
            {
                if (i != j && isSubsequence(strs[i], strs[j]))
                {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique)
            {
                ans = max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};
